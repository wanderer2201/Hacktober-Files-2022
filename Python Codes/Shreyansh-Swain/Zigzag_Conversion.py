'''The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for
better legibility)  And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows); '''


class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        result = [""] * numRows
        rowNumber = 0
        direction = 1      
 
        for i in range(len(s)):  #looping through each element
            result[rowNumber] = result[rowNumber] + s[i]
            if rowNumber < numRows -1 and direction == 1:
                rowNumber += 1
            elif rowNumber > 0 and direction == -1:
                rowNumber -= 1
            else:
                direction *= -1
                rowNumber += direction
 
        return ''.join(result)
