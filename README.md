# CS-210-AirAirgeadBankingInvestementApp

  This project was created for my CS-210 course at Southern New Hapshire University. It is the start of an investment calculator application that would be used by a bank.
  The program is structuted around an investment class and is driven by a do/while loop in main. The program accepts input from the user to define an an initial investment amount,
  a monthly deposit amount, the annual intrest rate, and how many years to calculate. It then prints 2 data calculations. The first is yearly balance and intrest earned with no
  monthly deposit, the second is with the monthly deposits. It encourages the user to make monthly deposits with the bank by showing the difference between the 2. 

  This program creates the new Investment using the c++14 std::make_unique that utilizes dynamic memory allocation. This is good because it ensure memory is properly deallocated 
  when the pointer goes out of scope. This is safer and prefered over just using new. The program I believe is also easy to follow with good in-line comments, code structure, and a simple main function.

  One issue with this code is when getting the userChoice, to continue the program the user has to input a character. The interface would be more streamline if the user could press any button, (like enter) to continue. 
  There could also be more detailed exceptions added to the try/catch in main. As the program is simple, I dont believe any issues to arise from this, but it would be a good idea in future iterations to help with debugging. 
  Lasty, it's possible the input validation in the readDataInput method could be written simplier. All of the do/while loops in that method are my least favorite part of the code. 

  The most difficult part of building this program was getting the calculations to be correct. It took me too long to realize the logical mistake I was making dividing a float by an integer value. Websites like StacksOverflow
  and GeeksforGeeks have been bookmarked on my browser.

  Learning the safe way to instantiate class objects with make_unique will be valuable in future programs. Also, working with pointers will be invaluable experience to help me in the future.

  
