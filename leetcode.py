import sys
import argparse
import json
import httplib
import re
import datetime
import random
# installed
import jsonpickle

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
	def __init__(self, id, title, acceptance = 0.0, difficulty = "Easy"):
		# require
		self.id = id
		self.title = title
		# optional
		self.difficulty = difficulty
		self.acceptance = acceptance
		# suggested
		self.description = ""
		self.category = "Algorithms"
		self.language = "C++"
		self.trial = 0
		self.duration = datetime.timedelta(hours = 1)
		self.accepted = datetime.datetime.min
		LeetcodeProblem.directory.append(self)
	def solve(self, duration, trial):
		self.accpeted = datetime.datetime.now()
		self.trial = trial
		self.duration = duration
	def score(self):
		return 5 * self.duration.seconds / 60 + 10 * self.trial + (datetime.datetime.now() - self.accepted).seconds / 86400
	def __str__(self):
		return str(self.id) + ": " + self.title + "(" + str(self.duration.seconds / 60) + "/" + str(self.trial) + "/" + str((datetime.datetime.now() - self.accepted).seconds / 86400) + ")"
class Leetcode:
	def __init__(self, jsonfile = None):
		self.index = {}
		if jsonfile:
			self.load(jsonfile)
		else:
			conn = httplib.HTTPSConnection('leetcode.com')
			conn.request("GET", "/problemset/algorithms/")
			r = conn.getresponse()
			msg = r.read()
			m = re.search('<td>(\d+)</td>', msg)
			msg = msg[m.end():]
			while m:
				id = int(m.group(1))
				m = re.search('">(.*)</a>', msg)
				title = m.group(1)
				m = re.search('<td>(\d\d\.\d)%</td>', msg)
				acceptance = float(m.group(1))
				m = re.search("<td value='\d'>(\w+)</td>", msg)
				difficulty = m.group(1)
				prob = LeetcodeProblem(id, title, acceptance, difficulty)
				msg = msg[m.end():]
				m = re.search('<td>(\d+)</td>', msg)
				# in fact, it's possible to dig deeper for tag or description automatically
		for prob in LeetcodeProblem.directory:
			self.index[prob.id] = prob
			self.index[prob.title] = prob
	def reload(self, id):
		conn = httplib.HTTPSConnection('leetcode.com')
		conn.request("GET", "/problemset/algorithms/")
		r = conn.getresponse()
		msg = r.read()
		m = re.search("<td>%d</td>" % id, msg)
		msg = msg[m.end():]
		m = re.search('">(.*)</a>', msg)
		title = m.group(1)
		m = re.search('<td>(\d\d\.\d)%</td>', msg)
		acceptance = float(m.group(1))
		m = re.search("<td value='\d'>(\w+)</td>", msg)
		difficulty = m.group(1)
		prob = LeetcodeProblem(id, title, acceptance, difficulty)
		msg = msg[m.end():]
		m = re.search('<td>(\d+)</td>', msg)
		# in fact, it's possible to dig deeper for tag or description automatically
		self.index[prob.id] = prob
		self.index[prob.title] = prob
	def load(self, jsonfile = "db.json"):
		with open(jsonfile, "r") as f:
			LeetcodeProblem.directory = jsonpickle.decode(f.read())
	def save(self, jsonfile = "db.json"):
		with open(jsonfile, "w") as f:
			jstr = jsonpickle.encode(LeetcodeProblem.directory)
			jobj = json.loads(jstr)
			sys.stdout = f
			print json.dumps(jobj, indent = 4)
			sys.stdout = sys.__stdout__
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
# add a field
# map(lambda x : setattr(x, "duration", datetime.timedelta(hours = 1)), LeetcodeProblem.directory)
# del a field
# map(lambda x : delattr(x, "duration"), LeetcodeProblem.directory)

def main():
	p = argparse.ArgumentParser()
	p.add_argument("-f", "--jsonfile", help="the database file", default='db.json')
	args = p.parse_args()
	global lc
	lc = Leetcode(args.jsonfile)

if __name__ == "__main__":
	main()
