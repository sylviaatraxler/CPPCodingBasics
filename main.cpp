#include <cstdlib>
#include <iostream>
#include <list>


void GetPermutation(std::string base, std::string add, std::list<std::string>& list)
{
  if (add.length() == 1)
  {
     list.push_back(base + add);
  }
  else
  {
    // Append Base and Add strings
    for (int count = 0; count < add.length(); count++)
    {
      std::string first = base + add.substr(count,1);
      
      // Get the end of the string and the beginning minus the base char
      std::string last = add.substr(count+1,add.length()-1)+add.substr(0,count);

      // Recursive permitation finder -- 
      GetPermutation(first, last, list);
    }
  }
}

int main(int argc, char *argv[])
{
    std::string input = "";
    std::list<std::string> permutations;
    
    std::cout << "Please enter string for permutation or 0 to exit" << std::endl;
    std::cin >> input;  
    
    while (input.compare("0")) 
    {
      // Find Permutations --- 
      std::string base;
      std::string add = input;
      GetPermutation(base, add, permutations);
       
      // Print Results ---    
      for (std::list<std::string>::iterator item = permutations.begin(); 
           item != permutations.end(); 
           item++)
      {
        std::cout << *item << std::endl;
      } 
      
      // Reset the list
      permutations.clear();
      
      std::cout << "Please enter string for permutation or 0 to exit" << std::endl;
      std::cin >> input;  
    }
    
    std::system("PAUSE");
    return EXIT_SUCCESS;
}

