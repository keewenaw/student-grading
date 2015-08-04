#!/usr/bin/python
# 10/2013
# Argparse documentation - http://docs.python.org/2/library/argparse.html#module-argparse
# Zipfile documentation - http://docs.python.org/2/library/zipfile
# SMTPlib documentation - http://docs.python.org/2/library/email-examples.html
import os, sys, argparse, random, string, zipfile, datetime, smtplib, urllib2
from email.mime.text import MIMEText
from random import choice

OPT_OUT_STRING = "optout" # String to search for in header comments
FILENAME = "submissions.zip" # File from BB or wherever
ID_MAPPING_FILE = "id_mapping.txt" # student ID/random string mapping list
WORKING_DIR = "submissions" # Temporary place to store files from tgz
STUDENTS_LIST = [] # Random array of random IDs

def main(): # If a comment is needed here, there's nothing I can do for you
	parse_cmdln_args()
	extract_submissions(FILENAME)
	remove_optouts()
	random_ids = rename_files()
	strip_headers()
	define_students_to_grade(random_ids)
	#upload_files()
	#send_mail()
	print_all_info()

def parse_cmdln_args(): # Parse all command-line args, if they exist
	global OPT_OUT_STRING, FILENAME
	parser = argparse.ArgumentParser(description='Unzip, rename, and assign random names to submissions')
	parser.add_argument('-o', dest='OPT_OUT_STRING', help="The opt-out string (from header) to find and filter on (default: \'# optout\')")
	parser.add_argument('-f', dest='FILENAME', help="The compressed .zip file to mess with (default: \'submissions.zip\')")
	parser.add_argument('-m', dest='ID_MAPPING_FILE', help="The .file that stores mappings between student IDs and anonymous IDs (default: \'id_mapping.txt\')")
	args = parser.parse_args()
	if args.OPT_OUT_STRING:
		OPT_OUT_STRING = args.OPT_OUT_STRING
	if args.FILENAME:
		FILENAME = args.FILENAME
	if args.ID_MAPPING_FILE:
		ID_MAPPING_FILE = args.ID_MAPPING_FILE

def extract_submissions(submissions): # Extract the submissions archive into a temp directory, working_dir
	f = zipfile.ZipFile(submissions, "r")
	if not os.path.exists(WORKING_DIR):
		os.mkdir(WORKING_DIR)
	f.extractall(WORKING_DIR)
	f.close()

def remove_optouts(): # If the file has OPT_OUT_STRING, delete it
	os.chdir(os.getcwd() + "/" + WORKING_DIR)
	current_dir = os.getcwd()
	for filename in os.listdir('.'):
		f = open(filename, "r")
		lines = f.readlines()
		opted_out = False
		for line in lines:
			if OPT_OUT_STRING in line:
				opted_out = True
				break
		f.close()
		if opted_out:
			os.remove(filename)
	os.chdir("../")

def rename_files(): # Move to WORKING_DIR, rename all C++ source files to random string, and delete everything else
	random_name_list = []
	os.chdir(os.getcwd() + "/" + WORKING_DIR)
	current_dir = os.getcwd()
	for filename in os.listdir('.'):
		if filename.endswith(".cc") or filename.endswith(".cpp"):
			sid = filename.split("_")[1]
			new_name = ''.join(random.choice(string.ascii_lowercase) for x in range(6)) # 6 char string made
			STUDENTS_LIST.append(Student(sid, new_name))
			random_name_list.append(new_name)
			os.rename(filename, current_dir + "/" + new_name + ".cpp")
		else:
			os.remove(current_dir + "/" + filename)
	os.chdir("../")
	return random_name_list

def strip_headers(): # Remove all header comments (the PII)
	os.chdir(os.getcwd() + "/" + WORKING_DIR)
	for filename in os.listdir('.'):
		f = open(filename, "r") # http://stackoverflow.com/questions/4710067/deleting-a-specific-line-in-a-file-python
		lines = f.readlines()
		f.close()
		f = open(filename, "w")
		in_header = True
		for line in lines:
			if '#include' not in line and in_header == True:
				continue
			else:
				in_header = False
				f.write(line)
		f.close()
	os.chdir("../")

def define_students_to_grade(name_list): # Pick 4 other IDs to grade
	for nl in name_list:
		count = 0
		while count < 4:
			rand_int = random.randint(0, len(name_list) - 1)
			if STUDENTS_LIST[rand_int].get_random_id() != nl and STUDENTS_LIST[rand_int].get_grading_list().find(nl) < 0 and STUDENTS_LIST[rand_int].get_count() < 4:
				STUDENTS_LIST[rand_int].add_id(nl)
				count = count + 1

def upload_files(): # Upload files to the server
	os.chdir(os.getcwd() + "/" + WORKING_DIR)
	url = 'http://localhost:5544'
	#for filename in os.listdir('.'):
	#	r = requests.post(url, files={filename: open(filename, 'rb')}) # http://docs.python-requests.org/en/latest/user/quickstart/#post-a-multipart-encoded-file
	f = open(filename, "r")
	lines = f.readlines()
	f.close()
	values = { "description": "Code+for+" + filename.split(".")[0], "form-0-language": "CppLexer%3B.cpp", "form-0-filename": filename, "form-0-priority": "0", "form-0-paste": '+'.join(lines), "expires": "never", "csrfmiddlewaretoken": "c15536b3dcc3655e901dc58f38743aaf", "form-TOTAL_FORMS": "1", "form-INITIAL_FORMS": "0", "form-MAX_NUM_FORMS": "" } # http://stackoverflow.com/questions/3659595/making-http-post-request


	data = urllib.urlencode(values)
	req = urllib2.Request(url, data)
	#response = urllib2.urlopen(req)
	#print response.geturl()
	#print response.info()
	#the_page = response.read()
	#print the_page
	f.close()
		
	os.chdir("../")	

def send_mail(ids_to_grade): # Send each student an email with the random IDs they need to grade
	current_date = datetime.date.today().isoformat()
	username = "" # For gmail acct
	password = "" 
	sender = username + "@school.edu"
	server = smtplib.SMTP('imap.school.com:587')
	server.starttls()
	server.login(sender, password)

	for s in STUDENTS_LIST:
		reciever = s.get_id() + "@school.edu"
		msg = MIMEText("The programs you have to grade are: " + s.get_grading_list())
		msg["From"] = sender
		msg["To"] = reciever
		msg["Subject"] = current_date + ": Assignments to Grade"
		server.sendmail(sender, reciever, msg.as_string())
	server.quit()

def print_all_info(): # All students + their random strings + 4 IDs they're grading
	f = open(ID_MAPPING_FILE, "a")
	f.write("ID\t\tRandom ID\tPeople to grade\n\n")
	for s in STUDENTS_LIST:
		f.write(s.to_string() + "\n")
	f.close()

class Student: # ID + random ID + 4 IDs to grade
	def __init__(self, n, r, g=None):
		self.sid = n
		self.random_id = r
		self.grading_list = ""
		self.count = 0

	def get_sid(self):
		return self.sid
	
	def get_random_id(self):
		return self.random_id
	
	def get_grading_list(self):
		return self.grading_list

	def get_count(self):
		return self.count

	def add_id(self, i):
		self.grading_list = self.grading_list + i + " "
		self.count = self.count + 1

	def to_string(self):
		return self.sid + "\t\t" + self.random_id + "\t\t" + self.grading_list

if __name__ == "__main__":
    main()
