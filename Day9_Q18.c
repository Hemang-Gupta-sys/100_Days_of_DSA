/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.*/

#include <stdio.h>
#define N 100
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }   
}
int main() {
    char s[N];
    
    printf("Enter the string to reverse: ");
    scanf("%s", s);
    
    int sSize = 0;
    while (s[sSize] != '\0') {
        sSize++;
    }
    
    reverseString(s, sSize);
    
    printf("Reversed string: %s\n", s);
    
    return 0;
}