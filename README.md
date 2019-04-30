# student-grading
A quick Python script to anonymize student-submitted projects and randomly assign peer reviewers for grading.

Note: I've tried to remove personally-identifiable information, including emails, names, etc.

Background: Back in grad school, I was requested to create a script that would help a professor automate 
the process of 
1) anonymizing student code project submissions 
2) randomly assigning other students' projects to grade

This Python script accepted a ZIP file of students' C++ code files. The script then tore out any personally
identifiable information and renamed the file to anonymize it. Then it took a list of students, gave them 
a random ID number, and assigned each ID four other IDs to grade (for peer grading). For safety, we added an 
"optout" key to put in the file header; any files that had this key wouldn't be handled at all.

<i>Terms and conditions: This is provided for free and can be used in any manner you see fit, ONLY IF you clearly and prominently credit me as the original author (either by my Github handle @mrudy or my Twitter handle @keewenaw). If you use this, you take all responsibility for anything you may do with it or anything it does to your systems. Doing anything with this repo or code signifies acceptance of these conditions.</i>
