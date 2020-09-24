#!/usr/bin/env python3

import sys, re, os, mimetypes
import argparse
import requests
import functools
from select import select

parser = argparse.ArgumentParser(description='Simulates x86prime machine code.\n  Be aware that this script cannot take inputs from stdin. However is does support command-line arguments.\n  Execution time is limited to 5 minutes.')
parser.add_argument('file', metavar='hex-file',
                    help='file with x86prime machine code to simulate')
parser.add_argument('prg', metavar='program',
                    help='top program')
parser.add_argument('args',
                      # action='store',
                      help='Arguments to program',
                      nargs='*', type=int)
parser.add_argument('-show', dest='show', action='store_const',
                    const=True, default=False,
                    help='show simulation')
parser.add_argument('-tracefile', dest='trace',
                    help='Write trace to this file')

args = parser.parse_args()

if args.file==None :
  print("Program needs an input file.\n")
  parser.print_help()
  exit()

if args.prg==None :
  print("Program needs an top function.\n")
  parser.print_help()
  exit()

extensions = args.file.split(".")
fileextension = extensions[-1]

expected_fileextension = "hex"
if fileextension != expected_fileextension:
  print("The input is expected to be a assembler program; fileextension '"+expected_fileextension+"'.\n")
  exit()

if not os.path.isfile(args.file):
  print("Input file does not exist: "+args.file+"\n")
  exit()

extensions[-1] = "sym"
symfile = ".".join(extensions)
if not os.path.isfile(symfile):
  print("Input file does not exist: "+args.file+"\n")
  exit()

file = open(args.file, 'r')
args.fileCont = file.read()
file.close()

file = open(symfile, 'r')
symfile_cont = file.read()
file.close()

# Read arguments for stdin if they are piped
input = ""
timeout = 0.1
rlist, _, _ = select([sys.stdin], [], [], timeout)
if rlist:
  for line in sys.stdin:
    line = line.rstrip("\n\r")
    input += line+" "

# x86prime Online location
URL = "http://topps.diku.dk/compsys/prun.php"
# Args as string
strargs = functools.reduce((lambda x, y: x+" "+str(y)), args.args, "")
# defining a params dict for the parameters to be sent to the API
DATA = {'file':args.fileCont,'sym':symfile_cont,"prg":args.prg, "show":args.show, "trace":args.trace, "args":(input+strargs)}
# sending get request and saving the response as response object
r = requests.post(url = URL, data = DATA)

# location of results
URLDIR = "http://topps.diku.dk/compsys/x86prime_runs/"
# extracting data in json format, only first line
runid = r.text.split('\n', 1)[0]
# print(r.text) # Debug

# get possible error code from execution
error = requests.get(url = URLDIR+runid+".error")

if error.text != "":
  # if error print this
  print(error.text)
  exit()
else:
  if args.show == True:
    # if success write the output to file in same dir as input file
    # This is the behaviour of primify, though not the best.
    extenstion_to_get = "sim"
    output = requests.get(url = URLDIR+runid+"."+extenstion_to_get)
    print(output.text)

  if args.trace != None:
    # Write trace
    trace = requests.get(url = URLDIR+runid+".trc")
    file = open(args.trace, 'w')
    args.fileCont = file.write(trace.text)
    file.close()
