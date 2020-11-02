import sys
import os

SPACING = 9

keys = input('gimme da keymap: ')
output = ''
row_count = 0
for key in [x.strip() for x in keys.split(',')]:
    output += key + ','
    output += ' ' * (SPACING-len(key)+1)
    if row_count == 11:
        row_count = 0
        output += '\\\n'
    else:
        row_count += 1

print(output)

