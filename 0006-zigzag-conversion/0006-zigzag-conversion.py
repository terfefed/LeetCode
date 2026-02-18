class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        
        rows = [""] * numRows
        curRow = 0
        direction = 1
        
        for ch in s:
            rows[curRow] += ch
            curRow += direction
            
            if curRow == 0 or curRow == numRows - 1:
                direction *= -1
        
        return "".join(rows)