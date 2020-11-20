// RAM[0] and RAM[1] will be used to take numbers
// which will be compared later. And the result will be
// stored in the variable called max

  @R0
  D=M              // D = n1
  @R1
  D=D-M            // D = n1 - n2
  @FM
  D;JGT            // if D>0 (n1>n2) goto FM
  @R1
  D=M              // D = n2
  @SM
  0;JMP            // goto SM

(FM)
  @R0
  D=M              // D = first number

(SM)
  @R2
  M=D              // M[2] = D (greatest number)

(END)
  @END
  0;JMP            // END