import java.util.Scanner;
public class MolecularMass {

    public static void main(String args[]){
        IntStack stack = new IntStack();
        int mass = 0;
        int mult, asc, add, comb, temp;
        char hold;

        System.out.print("Enter the molecule: ");
        Scanner sc = new Scanner(System.in);
        String molec = sc.nextLine();

        
        for(int i = 0; i < molec.length(); i++) {
            hold = ' ';

            if(molec.charAt(i) == 'h' || molec.charAt(i) == 'H')
            {
                stack.push(1);    
            }
            else if(molec.charAt(i) == 'c' || molec.charAt(i) == 'C')
            {
                stack.push(12);      
            }
            else if(molec.charAt(i) == 'o' || molec.charAt(i) == 'O')
            {
                stack.push(16);   
            }
            else if(molec.charAt(i) != 'h' && molec.charAt(i) != 'H' && molec.charAt(i) != 'c' && molec.charAt(i) != 'C' && molec.charAt(i) != 'o' && molec.charAt(i) != 'O')
            {
                hold = molec.charAt(i);   
                if(hold == '(')
                {

                    comb = 0;
                    i++;
/*while in ()*/         while(molec.charAt(i) != ')')
                        {
/*H in ()*/                 if(molec.charAt(i) == 'h' || molec.charAt(i) == 'H')
                            {
/*if *# next to mol in ()*/     if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                    && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {
                                        
                                         asc = molec.charAt(i + 1) - '0';
                                         comb = comb + (1 * asc);
                                         i = i + 2;
                                }
                                else {
                                    comb = comb + 1;
                                    i++;
                                }
                                 
                            }
/*C in ()*/                 else if(molec.charAt(i) == 'c' || molec.charAt(i) == 'C')
                            {
                               if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                        && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {
                             
                                    asc = molec.charAt(i + 1) - '0'; 
                                    comb = comb + (12 * asc);
                                    i = i + 2;          
                                }   
                                else {
                                    comb = comb + 12;
                                    i++;
                                }
                                 
                            }
/*O in ()*/                 else if(molec.charAt(i) == 'o' || molec.charAt(i) == 'O')
                            {
                                if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                    && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {

                                    asc = molec.charAt(i + 1) - '0';
                                    comb = comb + (16 * asc);
                                    i = i + 2;
                                }
                                else {
                                 comb = comb + 16;
                                 i++;
                                }
                            }
/*() in ()*/                else if(molec.charAt(i) == '(')
                            {
                                comb = 0;
                                i++;
                                while(molec.charAt(i) != ')') {
                                    if(molec.charAt(i) == 'h' || molec.charAt(i) == 'H') {
                                        if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                            && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {

                                            asc = molec.charAt(i + 1) - '0';
                                            comb = comb + (1 * asc);
                                            i = i + 2;
                                        }
                                        else
                                        {
                                            comb = comb + 1;
                                            i++;
                                        }
                                    }
                             else if(molec.charAt(i) == 'c' || molec.charAt(i) == 'C') {
                                 if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                     && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {
                                        asc = molec.charAt(i + 1) - '0';
                                        comb = comb + (12 * asc);
                                        i = i + 2;
                                 }
                                 else {
                                    comb = comb + 12;
                                    i++;
                                 }
                             }
                             else if(molec.charAt(i) == 'o' || molec.charAt(i) == 'O')
                             {
                                    if(molec.charAt(i + 1) != 'h' && molec.charAt(i + 1) != 'H' && molec.charAt(i + 1) != 'c' && molec.charAt(i + 1) != 'C'
                                        && molec.charAt(i + 1) != 'o' && molec.charAt(i + 1) != 'O' && molec.charAt(i + 1) != ')' && molec.charAt(i + 1) != '(') {
                                                   asc = molec.charAt(i + 1) - '0';
                                                   comb = comb + (16 * asc);
                                                   i = i + 2;
                                }
                                else {
                                 comb = comb + 16;
                                 i++;   
                                }
                             }
                             else {
                                asc = molec.charAt(i) - '0';
                                asc = asc * comb;
                                 stack.push(asc);

                             }
                    }//end nested while

              }//END OF ()in()

            
                        } //end of while
/*multiply comb*/       if(molec.charAt(i) == ')') 
                        {
                            asc = molec.charAt(i + 1) - '0';
                            comb = comb * asc;
                            stack.push(comb);
                            i = i + 2;
                        }
                      }//end of if(hold)
                      else { //just a regular multiplyer
                        mult = stack.pop();
                        asc = molec.charAt(i) - '0';
                        asc = asc * mult;
                        stack.push(asc);

                      }

                 } //end of else if
                 
            } // end of for

       
        
        int x = 0;
        while(x != -1)
        {
            add = stack.pop();
            x = add;
            mass = mass + add;

        }
        mass = mass + 1;

        System.out.println("The Molecular Mass of " + molec + " is " + mass);
        
    }
}
