"""
leetcode aux
"""
import sys
import argparse
import json
import httplib
import re
# installed
import jsonpickle

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
		# self.accepted = timedate
		self.source = ""
		LeetcodeProblem.directory.append(self)

class Leetcode:
	def __init__(self):
		conn = httplib.HTTPSConnection('leetcode.com')
		conn.request("GET", "/problemset/algorithms/")
		r = conn.getresponse()
		msg = r.read()
		m = re.search('<td>(\d+)</td>', msg)
		msg = msg[m.end():]
		while m:
			id = int(m.group(1))
			print "id:", id
			m = re.search('">(.*)</a>', msg)
			title = m.group(1)
			print "title:", title
			m = re.search('<td>(\d\d\.\d)%</td>', msg)
			acceptance = float(m.group(1))
			print "acceptance:", acceptance
			m = re.search("<td value='\d'>(\w+)</td>", msg)
			difficulty = m.group(1)
			print "difficulty:", difficulty
			prob = LeetcodeProblem(id, title, acceptance, difficulty)
			msg = msg[m.end():]
			m = re.search('<td>(\d+)</td>', msg)
			# in fact, it's possible to dig deeper for description automatically
		return
	def load(self, jsonfile):
		with open(jsonfile, "r") as f:
			LeetcodeProblem.directory = jsonpickle.decode(f.read())
		return
	def save(self, jsonfile):
		with open(jsonfile, "w") as f:
			jstr = jsonpickle.encode(LeetcodeProblem.directory)
			jobj = json.loads(jstr)
			sys.stdout = f
			print json.dumps(jobj, indent = 4)
			sys.stdout = sys.__stdout__

leetcode = Leetcode()

def init():
	"""
	load database
	"""
def test():
	"""help of test
	help me
	"""
	print "hello, leetcode"

def main():
	p = argparse.ArgumentParser()
	p.add_argument("-f", "--jsonfile", help="the database file", default=None)
	args = p.parse_args()
	if args.jsonfile:
		global leetcode
		leetcode.load(args.jsonfile)
	return

if __name__ == "__main__":
	main()
