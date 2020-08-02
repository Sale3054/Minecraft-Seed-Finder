#!/usr/bin/env python3
import re
import sys

if __name__ == "__main__":
    pattern = re.compile("^-?[0-9]{18}\n")
    count = 0
    seed_list = []
    print(f"Looking for seeds in the file that match...what a seed looks like in '{sys.argv[1]}'")
    for i, line in enumerate(open(sys.argv[1])):
        for match in re.finditer(pattern, line):
            count += 1
            seed_list.append(match.group().rstrip('\n'))

    print(f"Found {count} seeds in '{sys.argv[1]}'.")
    print(f"First 5: {seed_list[:5]}...")

    print(f"Writing seeds to {sys.argv[2]}...")


    #open a new file at the second input file name and write the seeds to that file
    with open(sys.argv[2], 'w') as filehandle:
        for listitem in seed_list:
            filehandle.write('%s\n' % listitem)

    print("Done.")
