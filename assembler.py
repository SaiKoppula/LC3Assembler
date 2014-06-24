import sys,re

infile = sys.argv[1]
outfile = infile[0:len(infile)-4]+"-compiled.asm"

lc3x_opcodes = {'MUL', 'DIV', 'SUB', 'OR', 'XOR'}
lc3b_opcodes = {'ADD', 'AND', 'BR', 'BRn', 'BRz', 'BRp', 'BRnz', 'BRzp', 'BRnp', 'BRnzp', 'JMP', 'JSR', 'JSRR', 'LDB', 'LDI', 'LDR', 'LEA', 'NOT', 'RTI', 'SHF', 'STB', 'STI', 'STR', 'TRAP'}

def FselBits(y):
    return{
	'SUB': '000',
	'MUL': '001',
	'DIV': '010',
	'XOR': '011',
	'OR' : '100'
    }[y]
def process(operand_line):
    operand_list = re.findall(r"[\w']+", operand_line)
    if len(operand_list) < 4:
	print "Possible Error in line: "
	print operand_line
	return operand_line
    else:
	try:
	    binInstr = '1000'+regNum(operand_list[1])+regNum(operand_list[2])+FselBits(operand_list[0])+regNum(operand_list[3])
	except (KeyError):
	    print "Error in line: "
	    print operand_line
	    return operand_line
	    
	instr = hex(int(binInstr,2))
	instr = '\tDATA2 4' + instr[1:6]
	return instr

n = 0;
open(outfile, "w").close()
with open(infile) as inf, open(outfile, "w") as outf:
    for line in inf:
	word_list =  re.findall(r"[\w']+", line)

	if len(word_list) > 0 and word_list[0] in lc3x_opcodes:
	    lc3x_instr = process(line)
	    outf.writelines(lc3x_instr)
	    outf.writelines('\n')
	else:
	    outf.writelines(line)


