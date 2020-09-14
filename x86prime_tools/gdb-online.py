#!/usr/bin/env python3

import sys, re, os, mimetypes, argparse, requests

parser = argparse.ArgumentParser(description='Compiles a C program into a gcc output x86_64.')

parser.add_argument('gdb', metavar='gdb-script',
                    help='Your gdb script')
parser.add_argument('file', metavar='C-file',
                    help='your implementation of file')


args = parser.parse_args()

extensions = args.file.split(".")
fileextension = extensions[-1]

if not os.path.isfile(args.gdb):
  print("Input file does not exist: "+args.gdb+"\n")
  exit()

gdb = open(args.gdb, 'r')
args.gdbCont = gdb.read()
gdb.close()


if fileextension != "c":
  print("The input is expected to be a C program; fileextension 'c'.\n")
  exit()

if not os.path.isfile(args.file):
  print("Input file does not exist: "+args.file+"\n")
  exit()

file = open(args.file, 'r')
args.fileCont = file.read()
file.close()




# x86prime Online location
URL = "http://topps.diku.dk/compsys/gdb.php"
# defining a params dict for the parameters to be sent to the API
DATA = {"file":args.fileCont, "gdb":args.gdbCont}
# sending get request and saving the response as response object
r = requests.post(url = URL, data = DATA)

URLDIR = "http://topps.diku.dk/compsys/gcc_runs/"
# extracting data in json format
runid = r.text

print (runid)

error = requests.get(url = URLDIR+runid+".error")

if error.text != "":
  print(error.text)
  exit()
else:
  gdb = requests.get(url = URLDIR+runid+".out")
  print (gdb.text)
  # if args.output != None:
  # else:
  #   print(assembler.text)
