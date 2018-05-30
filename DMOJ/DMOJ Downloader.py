import requests
import os
import time

def extension(language):
	if language[0:2]=='PY': return '.py'
	elif language[0:4]=='JAVA': return '.java'
	elif language[0]=='C': return '.cpp'
	else:
		print("Language not found: ", language)
		return '.txt'

def toFileName(name):
        d = {'/':'-', '\\':'-', '*':'', '?':'', ':':'-', '<':' ', '>':' ', '"':"'", "|":'-'}
        for i in d:
                name=name.replace(i, d[i])
        return name

def saveProblem(group, name, language, text):
    f = open(group+"/"+toFileName(name)+extension(language), "w")
    f.write(text.encode('cp1252', errors='replace').decode('cp1252'))
    f.close()
header = {
    "Cookie":"__cfduid=d8a420c3795ac58756909d04d87481d531527441930; csrftoken=G8ukzRdSPurpCqeJVzsJrpLkM31d4w4QiaXZJrUjBHSkb3kC1VHL20KVa4tAjgcv; _ga=GA1.2.1667111855.1527441933; sessionid=zo1mpi3fnbdvz0e6maqghmzetg5fu6bj; _gid=GA1.2.852465326.1527630887; _gat=1" #whatever your Cookie header is
    }

def getSubmission(submissionId):
        return requests.get("https://dmoj.ca/src/"+submissionId+"/raw", headers=header).text.replace('\r\n', '\r').replace('\r', '\n')

# returns whether submission a is better than submission b
def better(a, b):
	if not a["points"] == b["points"]:
		return a
	if a["points"] < b["points"]:
		return b
	if a["time"] < b["time"]:
		return a
	return b



username = "PlasmaVortex" #whatever your username is
subs = requests.get("https://dmoj.ca/api/user/submissions/"+username).json() # a map from the submission id to the submission data
#remove submissions with compile errors or aborted submissions, because those can have null time, points, or memory
subs = {i:subs[i] for i in subs if subs[i]["status"] == "D"}

problems = requests.get("https://dmoj.ca/api/problem/list").json() # a map from problem name to the problem data

best = {} # a map from problem name to the submission id of the best submission
for i in subs:
	p = subs[i]["problem"]
	if (p not in best or p in best and better(subs[i], subs[best[p]])):
		best[p] = i

#set up folders for different categories/contests
groups = {problems[p]["group"] for p in best}
for name in groups:
    os.makedirs(name, exist_ok=True)
count = 0
for p in best:
    r = getSubmission(best[p]) # the code
    time.sleep(0.2) # 5 API calls per second
    saveProblem(problems[p]['group'], problems[p]['name'], subs[best[p]]['language'],r)
    count+=1
    if (count%10==0): print(count)

print("Done")
