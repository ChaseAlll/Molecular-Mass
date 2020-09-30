#include <stdio.h>
#include <string.h>

#define LIMIT 40

void printAssembly(char filename[]);
void printAdd(int instruction);
void printAnd(int instruction);
void printBr(int instruction, int pc);
void printJmpRet(int instruction);
void printJsrJsrr(int instruction, int pc);
void printLd(int instruction, int pc);
void printLdi(int instruction, int pc);
void printLdr(int instruction);
void printLea(int instruction, int pc);
void printNot(int instruction);
void printRti(int instruction);
void printSt(int instruction, int pc);
void printSti(int instruction, int pc);
void printStr(int instruction);
void printTrap(int instruction);

//**************************************************
//Make sure to comment main out before submitting
//**************************************************

//int main()
//{
//	char filename[] = "test1.hex";
//	printAssembly(filename);
//}



void printAssembly(char filename[])
{
	FILE *infile;	
	infile = fopen(filename, "r");
	
	if (infile == NULL)	{
		printf("File %s is null.\n", filename);			
	} else {
    int count = 0;
    int instruction = 0;
    int start = 0;

    //Read the initial PC as an integer and save
    
    //While not at end of file and not over the limit
    while (fscanf(infile, "%x", &instruction) != EOF && count < LIMIT) {
      count++;  //Count number of lines for limit
      
       int pc = count + start;

      int opcode = (instruction >> 12) & 15;
      if(count == 1)
      {
          start = instruction;
        //  printf("%x\n", start); //comment this out
      }
      //Remove the print and put your code here
      else if(opcode == 1)
      {
          printAdd(instruction);
      }
      else if(opcode == 5)
      {
        printAnd(instruction);
      }
      else if(opcode == 0)
      {
        printBr(instruction, pc);
      }
      else if(opcode == 12)
      {
        printJmpRet(instruction);
      }
      else if(opcode == 4)
      {
          printJsrJsrr(instruction, pc);
      }
      else if(opcode == 2)
      {
          printLd(instruction, pc);
      }
      else if(opcode == 10)
      {
          printLdi(instruction, pc);
      }
      else if(opcode == 6)
      {
          printLdr(instruction);
      }
      else if(opcode == 14)
      {
          printLea(instruction, pc);
      }
      else if(opcode == 9)
      {
           printNot(instruction);
      }
      else if(opcode == 8)
      {
           printRti(instruction);
      }
      else if(opcode == 3)
      {
          printSt(instruction, pc);
      }
      else if(opcode == 11)
      {
          printSti(instruction, pc);
      }
      else if(opcode == 7)
      {
           printStr(instruction);
      }
      else if(opcode == 15)
      {
          printTrap(instruction);
      }


      // printf("%X\n", instruction);
      //Increment the PC
      //Figure out the oppcode from the high order 4 bits of the instruction
      //Use a big if or switch to call the appropriate print function.
      //Pass the function the full instruction and the PC, but only if necessary.
      
    }
  }
}

void printAdd(int instruction)
{
    
    int imc, neg = 0;
    int inst  = instruction;
    int dr, sr1, sr2 = 0;
    dr = (inst >> 9) & 7;
    sr1 = (inst >> 6) & 7;
    imc = (inst >> 5) & 1;
    

    if(imc == 0)
    {
        sr2 = inst & 7;
        printf("ADD\tR%d, R%d, R%d\n", dr, sr1, sr2); 
    }
    else
    {
        sr2 = inst & 31;
        neg = (inst >> 4) & 1;
        if(neg == 1)
        {
            sr2 = sr2 - 32;
        }
        printf("ADD\tR%d, R%d, #%d\n", dr, sr1, sr2);
    }
    
}

void printAnd(int instruction)
{
    int imc, neg = 0;
    int inst  = instruction;
    int dr, sr1, sr2 = 0;
    dr = (inst >> 9) & 7;
    sr1 = (inst >> 6) & 7;
    imc = (inst >> 5) & 1;

    if(imc == 0)
    {
        sr2 = inst & 7;
        printf("AND\tR%d, R%d, R%d\n", dr, sr1, sr2);
    }
    else
    {
        sr2 = inst & 31;
        neg = (inst >> 4) & 1;
        if(neg == 1)
        {
            sr2 = sr2 - 32;
        }
       printf("AND\tR%d, R%d, #%d\n", dr, sr1, sr2);
    }

}

void printBr(int instruction, int pc)
{
    int inst = instruction;
    int p = (inst >> 9) & 1;
    int z = (inst >> 10) & 1;
    int n = (inst >> 11) & 1;
    
    pc = pc - 1;
    int neg = (inst >> 8) & 1;
    int num = inst & 511;
    if(neg == 1)
    {
        num = num - 512;
    }
    int hex = num + pc;
    
    //nzp   nz  np  zp  n   z   p
    if(n == 1 && z == 1 && p == 1) //nzp  
    {
        printf("BRNZP\tx%X\n", hex);
    }
    else if(n == 1 && z == 1 && p != 1)   //nz
    {
        printf("BRNZ\tx%X\n", hex);
    }
    else if(n == 1 && p == 1 && z != 1)   //np
    {
        printf("BRNP\tx%X\n", hex);
    }
    else if(z == 1 && p == 1 && n != 1)   //zp
    {
        printf("BRZP\tx%X\n", hex);
    }
    else if(n == 1 && z != 1 && p != 1)   //n
    {
        printf("BRN\tx%X\n", hex);
    }
    else if(z == 1 && p != 1 && n != 1)   //z
    {
        printf("BRZ\tx%X\n", hex);
    }
    else if(p == 1 && n != 1 && z != 1)   //p
    {
        printf("BRP\tx%X\n", hex);
    }


   //printf("BR\t\n");
}

void printJmpRet(int instruction)
{
    int reg = (instruction >> 6) & 7;
    if(reg == 7)
    {
        printf("RET\n");
    }
    else
    {
        printf("JMP\tR%d\n", reg);
    }
}

void printJsrJsrr(int instruction, int pc)
{
    int foo = (instruction >> 11) & 1;
    int reg = (instruction >> 6) & 7;
    pc = pc - 1;
    int num = instruction & 2047;
    int neg = (instruction >> 10) & 1;
    if(neg == 1)
    {
        num = num - 2048;
    }
    pc = pc + num;

    if(foo == 1) //jsr
    {
        printf("JSR\tx%X\n", pc);
    }
    else //jsrr
    {
        printf("JSRR\tR%d\n", reg);
    }
}

void printLd(int instruction, int pc)
{
    int reg = (instruction >> 9) & 7;
    pc = pc - 1;
    int neg = (instruction >> 8) & 1;
    int num = instruction & 511;
    if(neg == 1)
    {
    num = num - 512;
    }
    pc = pc + num;
    printf("LD\tR%d, x%X\n", reg, pc);
}

void printLdi(int instruction, int pc)
{
    int reg = (instruction >> 9) & 7;
    pc = pc - 1;
    int neg = (instruction >> 8) & 1;
    int num = instruction & 511;
    if(neg == 1)
    {
        num = num - 512;
    }
    pc = pc + num;
    printf("LDI\tR%d, x%X\n", reg, pc);
}

void printLdr(int instruction)
{
    int reg1 = (instruction >> 9) & 7;
    int reg2 = (instruction >> 6) & 7;
    int neg = (instruction >> 5) & 1;
    int poo = instruction & 63;
    if(neg == 1)
    {
        poo = poo - 64;
    }
    printf("LDR\tR%d, R%d, #%d\n", reg1, reg2, poo);
}

void printLea(int instruction, int pc)
{
    int reg = (instruction >> 9) & 7;
    pc = pc - 1;
    int neg = (instruction >> 8) & 1;
    int num = instruction & 511;
    if(neg == 1)
    {
       num = num - 512;
    }
    pc = pc + num;
    printf("LEA\tR%d, x%X\n", reg, pc);
}

void printNot(int instruction)
{
    int reg = (instruction >> 9) & 7;
    int reg1 = (instruction >> 6) & 7;
    printf("NOT\tR%d, R%d\n", reg, reg1);
}

void printRti(int instruction)
{
    printf("RTI\n");
}

void printSt(int instruction, int pc)
{
    int reg = (instruction >> 9) & 7;
    pc = pc - 1;
    int neg = (instruction >> 8) & 1;
    int num = instruction & 511;
    if(neg == 1)
    {
    num = num - 512;
    }
    pc = pc + num;
    printf("ST\tR%d, x%X\n", reg, pc);
}

void printSti(int instruction, int pc)
{
    int reg = (instruction >> 9) & 7;
    pc = pc - 1;
    int neg = (instruction >> 8) & 1;
    int num = instruction & 511;
    if(neg == 1)
    {
       num = num - 512;
    }
    pc = pc + num;
    printf("STI\tR%d, x%X\n", reg, pc);
}

void printStr(int instruction)
{
    int reg = (instruction >> 9) & 7;
    int reg1 = (instruction >> 6) & 7;
    int poo = instruction & 63;
    int neg = (instruction >> 5) & 1;
    if(neg == 1)
    {
        poo = poo - 64;
    }

    printf("STR\tR%d, R%d, #%d\n", reg, reg1, poo);
}

void printTrap(int instruction)
{
    int foo = instruction & 15;
    if(foo == 0)
    {
        printf("GETC\n");
    }
    else if(foo == 1)
    {
        printf("OUT\n");
    }
    else if(foo == 2)
    {
        printf("PUTS\n");
    }
    else if(foo == 3)
    {
        printf("IN\n");
    }
    else if(foo == 4)
    {
        printf("PUTSP\n");
    }
    else if(foo == 5)
    {
        printf("HALT\n");
    }
}   

