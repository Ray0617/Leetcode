import sys
import argparse
import json
import httplib
import re
import datetime
import random
import json

# tested 10/04/2015
# usage:
# >>> lc.start("skyline")
# ### try coding on leetcode
# >>> lc.fail()
# >>> lc.fail()
# >>> lc.accept()
# or
# >>> lc.accept(trial=3)
# >>> lc.save(jsonfile="db.json")
# wanna random suggestion? try:
# >>> lc.random()
# wanna check a list? try:
# >>> lc.list(head=10)	# head = 10
class LeetcodeProblem:
	directory = []
	def __init__(self):
		# require
		self.id = 0
		self.title = ""
		# optional
		self.difficulty = "Easy"
		self.acceptance = 0.0
		# suggested
		self.description = ""
		self.category = "Algorithms"
		self.language = "C++"
		self.trial = 0
		self.duration = datetime.timedelta(hours = 24)
		self.accepted = datetime.datetime.min
		self.score = self.normalScore
		LeetcodeProblem.directory.append(self)
	def solve(self, duration, trial):
		self.accpeted = datetime.datetime.now()
		self.trial = trial
		self.duration = duration
		print duration
	def normalScore(self):
		return 5 * self.duration.seconds / 60 + 10 * self.trial + (datetime.datetime.now() - self.accepted).seconds / 86400
	def acceptScore(self):
		return self.accepted
	def __str__(self):
		return str(self.id) + ": " + self.title + "(" + str(self.duration.seconds / 60) + "/" + str(self.trial) + "/" + str((datetime.datetime.now() - self.accepted).seconds / 86400) + ")"
	def json(self):
		obj = {}
		obj['id'] = self.id
		obj['title'] = self.title
		obj['difficulty'] = self.difficulty
		obj['acceptance'] = self.acceptance
		obj['description'] = self.description
		obj['category'] = self.category
		obj['language'] = self.language
		obj['trial'] = self.trial
		obj['duration'] = self.duration.__repr__()
		obj['accepted'] = self.accepted.__repr__()
		obj['sort'] = self.score.__name__
		return obj
	@staticmethod
	def load(obj):
		prob = LeetcodeProblem()
		prob.id = obj['id']
		prob.title = obj['title']
		prob.difficulty = obj['difficulty']
		prob.acceptance = obj['acceptance']
		prob.description = obj['description']
		prob.category = obj['category']
		prob.language = obj['language']
		prob.trial = obj['trial']
		prob.duration = eval(obj['duration'])
		prob.accepted = eval(obj['accepted'])
		if obj['sort'] == 'normalScore':
			prob.sort = prob.normalScore
		elif obj['sort'] == 'acceptScore':
			prob.sort = prob.acceptScore
		return prob
class Leetcode:
	def __init__(self, jsonfile):
		self.index = {}
		try:
			self.load(jsonfile)
		except:
			conn = httplib.HTTPSConnection('leetcode.com')
			conn.request("GET", "/problemset/algorithms/")
			r = conn.getresponse()
			msg = r.read()
			m = re.search('<td>(\d+)</td>', msg)
			msg = msg[m.end():]
			while m:
				pid = int(m.group(1))
				m = re.search('">(.*)</a>', msg)
				title = m.group(1)
				m = re.search('<td>(\d\d\.\d)%</td>', msg)
				acceptance = float(m.group(1))
				m = re.search("<td value='\d+.\d%'>(\w+)</td>", msg)
				difficulty = m.group(1)
				prob = LeetcodeProblem()
				prob.id = pid
				prob.title = title
				prob.acceptance = acceptance
				prob.difficulty = difficulty
				msg = msg[m.end():]
				m = re.search('<td>(\d+)</td>', msg)
				# in fact, it's possible to dig deeper for tag or description automatically
		for prob in LeetcodeProblem.directory:
			self.index[prob.id] = prob
			self.index[prob.title] = prob
	def add(self, pid):
		conn = httplib.HTTPSConnection('leetcode.com')
		conn.request("GET", "/problemset/algorithms/")
		r = conn.getresponse()
		msg = r.read()
		m = re.search('<td>' + str(pid) + '</td>', msg)
		msg = msg[m.end():]
		m = re.search('">(.*)</a>', msg)
		title = m.group(1)
		m = re.search('<td>(\d\d\.\d)%</td>', msg)
		acceptance = float(m.group(1))
		m = re.search("<td value='\d+.\d%'>(\w+)</td>", msg)
		difficulty = m.group(1)
		prob = LeetcodeProblem()
		prob.id = pid
		prob.title = title
		prob.acceptance = acceptance
		prob.difficulty = difficulty
		self.index[prob.id] = prob
		self.index[prob.title] = prob

	def extend(self, jsonfile = "db.json"):
		with open(jsonfile, "r") as f:
			directory = jsonpickle.decode(f.read())
			index = {}
			for d in directory:
				index[d.id] = d
			for prob in LeetcodeProblem.directory:
				if prob.id in index:
					# id, title, difficulty, acceptance
					prob.description = index[prob.id].description
					# category, language
					prob.trial = index[prob.id].trial
					prob.duration = index[prob.id].duration
					if prob.duration == datetime.timedelta(hours=1):
						prob.duration = datetime.timedelta(hours=24)
					prob.accepted = index[prob.id].accepted
					print prob.score

	def load(self, jsonfile = "db.json"):
		with open(jsonfile, "r") as f:
			objs = json.load(f)
			print len(objs)
			LeetcodeProblem.directory = []
			for obj in objs:
				LeetcodeProblem.load(obj)
			return True
		return False
	def save(self, jsonfile = "db.json"):
		with open(jsonfile, 'w') as f:
			objs = []
			for prob in LeetcodeProblem.directory:
				objs.append(prob.json())
			json.dump(objs, f, indent=4)
	def sort(self, reverse = True):
		LeetcodeProblem.directory.sort(key=lambda x : x.score(), reverse = reverse)
	def start(self, prob):
		if prob in self.index:
			self.prob = self.index[prob]
		else:
			# try find the matchest one
			candidates = filter(lambda x : x.title.lower().count(prob[0:-1].lower()), LeetcodeProblem.directory)
			if len(candidates) > 1:
				ver = 1
				if prob.endswith("IV") or prob.endswith("4"):
					ver = 4
				elif prob.endswith("III") or prob.endswith("3"):
					ver = 3
				elif prob.endswith("II") or prob.endswith("2"):
					ver = 2
				candidates = filter(lambda x : self.match(x.title, ver), candidates)
			if len(candidates) > 1:
				print "More than One candidates match..."
				index = 0
				for candidate in candidates:
					print "(", index, ")", candidate
					index += 1
				sel = input("Enter an index: ")
				self.prob = candidates[sel]
			elif len(candidates) == 1:
				self.prob = candidates[0]
			else:
				print "Not found any candidate..."
				return
		print "Start the problem:", self.prob
		self.start_time = datetime.datetime.now()
		self.trial = 1
	def fail(self):
		self.trial += 1
	def accept(self, trial = None):
		if not trial:
			trial = self.trial
		self.prob.solve(datetime.datetime.now() - self.start_time, trial)
	def random(self):
		scores = 0
		for prob in LeetcodeProblem.directory:
			scores += prob.score()
		r = random.randint(0, scores - 1)
		for prob in LeetcodeProblem.directory:
			score = prob.score()
			if r < score:
				print prob
				return
			r -= score
	def list(self, head = 10, reverse = True):
		self.sort(reverse = reverse)
		for i in range(head):
			print LeetcodeProblem.directory[i]
	def match(self, prob, ver):
		if prob.endswith("IV"):
			return ver == 4
		if prob.endswith("III"):
			return ver == 3
		if prob.endswith("II"):
			return ver == 2
		return ver == 1
lc = None

def main():
	p = argparse.ArgumentParser()
	p.add_argument("-f", "--jsonfile", help="the database file", default="db.json")
	args = p.parse_args()
	global lc
	lc = Leetcode(args.jsonfile)

if __name__ == "__main__":
	main()
