#!/usr/bin/env python3

import sys, re, os, mimetypes, argparse, requests

parser = argparse.ArgumentParser(description='Transform gcc output to x86prime\', assemble and simulate.')
parser.add_argument('file', metavar='prime-file',
                    help='translate assemble file to x86prime')


args = parser.parse_args()

if args.file==None :
  print("Program needs an input file.\n")
  parser.print_help()
  exit()

extensions = args.file.split(".")
fileextension = extensions[-1]

expected_fileextension = "prime"
if fileextension != expected_fileextension:
  print("The input is expected to be a assembler program; fileextension '"+expected_fileextension+"'.\n")
  exit()

if not os.path.isfile(args.file):
  print("Input file does not exist: "+args.file+"\n")
  exit()

file = open(args.file, 'r')
args.fileCont = file.read()
file.close()

# x86prime Online location
URL = "http://topps.diku.dk/compsys/prasm.php"
# defining a params dict for the parameters to be sent to the API
DATA = {'file':args.fileCont}
# sending get request and saving the response as response object
r = requests.post(url = URL, data = DATA)

# location of results
URLDIR = "http://topps.diku.dk/compsys/x86prime_runs/"
# extracting data in json format
runid = r.text

# get possible error code from execution
error = requests.get(url = URLDIR+runid+".error")

if error.text != "":
  # if error print this
  print(error.text)
  exit()
else:
  # if success write the output to file in same dir as input file
  # This is the behaviour of primify, though not the best.
  extenstion_to_get = "hex"
  extensions[-1] = extenstion_to_get
  outfile = '.'.join(extensions)
  output = requests.get(url = URLDIR+runid+"."+extenstion_to_get)
  f=open(outfile,"w+")
  f.write(output.text)
  f.close

  extenstion_to_get = "sym"
  extensions[-1] = extenstion_to_get
  outfile = '.'.join(extensions)
  output = requests.get(url = URLDIR+runid+"."+extenstion_to_get)
  f=open(outfile,"w+")
  f.write(output.text)
  f.close
