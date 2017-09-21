#include <iostream>
#include <fstream>

#include "strings.h"

using namespace std;

/************************************************************************* 
*  Description: 
*            func to rotate a word by one unit starting at index n 
*  Parameter:  
*            string s - input string
*            int index - index to start the rotation from 
*  return:
*            void
**************************************************************************/

string RotateWord(string s, int index=0)
{
    string ret_str;
    for(int j = 0; j < index; j++)
        ret_str += s[j];
    ret_str += s[s.size()-1];
    ret_str += s.substr(index, s.size()-ret_str.size());
    return ret_str;
}




/************************************************************************* 
*  Description: 
*            function to print all the permutation of a word starting 
*            from index n 
*  Parameter:  
*            string s - input string
*            int index - index to start the permutation from 
*  return:
*            void
**************************************************************************/    
void PrintPermutation(string s, int index=0)
{
    string s_mod=s;
    int k = 0; 
    static int str_size = s.size();
    static ofstream out("permut_words.txt");
	
    if (str_size <=2)
    {
        while(str_size--)
        {
            out << s_mod << endl;
            s_mod = RotateWord(s_mod, index);
        }
    }   
    else
    {
        while(k++<str_size-index)
        {	       
            s_mod = RotateWord(s_mod, index);
            if(index>=str_size-3)
                out << s_mod << endl;
            if(index<str_size-2)
                PrintPermutation(s_mod, index+1);
            else
                break;
        }
    }
}





/************************************************************************* 
*  Description: 
*            function to remove the string from another string   
*  Parameter:  
*            string text - input string 
*            string remove_str - string to remove from "text" string 
*  return:
*            string ret_str - "text" string without "remove_str"
**************************************************************************/

string CensorString1(string text, string remove_str)
{
    unsigned int temp_cnt;
    char char_text, char_remove;
    string ret_str;

    temp_cnt=remove_str.size()-1;

    for (int i = 0; i<text.size(); i++)
    {
        char_text = text[i];
        for (int j=0; j<remove_str.size(); j++)
        {
            char_remove = remove_str[j];
            if(char_remove != char_text)
                break;
            else
            {
                char_text = text[i+j+1];
                if(j == temp_cnt)
                    text.erase(i, j+1);
            }
        }
    }
    ret_str = text;

    return ret_str;
}

// using more C++ string methods
string CensorString2(string text, string remove_str)
{
    unsigned int pos;
    string ret_str;


    for (int i = 0; i<text.size(); i++)
    {
        pos = text.find(remove_str);
        if(pos>=text.size())
            break;
        text.erase(pos,remove_str.size());
    }
    ret_str = text;

    return ret_str;
}
