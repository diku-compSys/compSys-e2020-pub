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
                      nargs='*', type=int,
                      help='Arguments to program')
parser.add_argument('-show', dest='show', action='store_const',
                    const=True,
                    help='show each simulation step')
parser.add_argument('-profile', dest='show', action='store_const',
                    const=True,
                    help='print an execution profile')

parser.add_argument('-bp_type',  dest='bp_type',
                    choices=['t','nt','btfnt','oracle','local','gshare'],
                    help='select type of branch predictor')
parser.add_argument('-bp_size', dest='bp_size', metavar='<size>', type=int,
                    help='select number of bits used to index branch predictor')
parser.add_argument('-rp_size', dest='rp_size', metavar='<size>', type=int,
                    help='select number of entries in return predictor')
parser.add_argument('-mem_lat', dest='mem_lat', metavar='<clks>', type=int,
                    help='number of clock cycles to read from main memory')

parser.add_argument('-d_assoc', dest='d_assoc', metavar='<assoc>',
                    help='associativity of L1 D-cache')
parser.add_argument('-d_lat', dest='d_lat', metavar='<latency>', type=int,
                    help='latency of L1 D-cache read')
parser.add_argument('-d_idx_sz', dest='d_idx_sz', metavar='<size>', type=int,
                    help='number of bits used for indexing L1 D-cache')
parser.add_argument('-d_blk_sz', dest='d_blk_sz', metavar='<size>', type=int,
                    help='number of bits used to address byte in block of L1 D-cache')

parser.add_argument('-i_assoc', dest='i_assoc', metavar='<assoc>',
                    help='associativity of L1 I-cache')
parser.add_argument('-i_lat', dest='i_lat', metavar='<latency>', type=int,
                    help='latency of L1 I-cache read')
parser.add_argument('-i_idx_sz', dest='i_idx_sz', metavar='<size>', type=int,
                    help='number of bits used for indexing L1 I-cache')
parser.add_argument('-i_blk_sz', dest='i_blk_sz', metavar='<size>', type=int,
                    help='number of bits used to address byte in block of L1 I-cache')

parser.add_argument('-l2_assoc', dest='l2_assoc', metavar='<assoc>',
                    help='associativity of L2 cache')
parser.add_argument('-l2_lat', dest='l2_lat', metavar='<latency>', type=int,
                    help='latency of L2 cache read')
parser.add_argument('-l2_idx_sz', dest='l2_idx_sz', metavar='<size>', type=int,
                    help='number of bits used for indexing L2 cache')
parser.add_argument('-l2_blk_sz', dest='l2_blk_sz', metavar='<size>', type=int,
                    help='number of bits used to address byte in block of L2 cache')
parser.add_argument('-dec_lat', dest='dec_lat', metavar='<latency>', type=int,
                    help='latency of decode stages')
parser.add_argument('-pipe_width', dest='pipe_width', metavar='<width>', type=int,
                    help='max number of insn fetched/clk')
parser.add_argument('-ooo', dest='ooo', action='store_const',
                    const=True,
                    help='enable out-of-order scheduling')
parser.add_argument('-pipe',  dest='pipe',
                    choices=['simple', 'super', 'ooo'],
                    help='select base pipeline configuration')
parser.add_argument('-mem',  dest='mem',
                    choices=['magic', 'real'],
                    help='select base memory configuration')
parser.add_argument('-print_config', dest='print_config', action='store_const',
                    const=True,
                    help='print detailed performance model configuration')

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

# x86prime Online location
URL = "http://topps.diku.dk/compsys/prerf.php"
# Args as string
strargs = functools.reduce((lambda x, y: x+" "+str(y)), args.args, "")
# Parsing flags
flaglist = ""
args_list = vars(args)
for key in args_list:
  if (key != 'file') & (key != 'args') & (key != 'prg') & (key != 'fileCont'):
    value = args_list[key]
    if value != None:
      if value == True:
        flaglist += ' -'+key
      else:
        flaglist += ' -'+key+' '+str(value)

# Read arguments for stdin if they are piped
input = ""
timeout = 0.1
rlist, _, _ = select([sys.stdin], [], [], timeout)
if rlist:
  for line in sys.stdin:
    line = line.rstrip("\n\r")
    input += line+" "

# defining a params dict for the parameters to be sent to the API
DATA = {'file':args.fileCont,'sym':symfile_cont,"prg":args.prg, "args":strargs, "flaglist":flaglist, "input":input}
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
  # if args.show == True:
    # if success write the output to file in same dir as input file
    # This is the behaviour of primify, though not the best.
  extenstion_to_get = "sim"
  output = requests.get(url = URLDIR+runid+"."+extenstion_to_get)
  print(output.text)

