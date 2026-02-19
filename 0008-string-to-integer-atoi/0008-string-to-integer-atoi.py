class Solution:
    def myAtoi(self,s:str)->int:
        res=''
        i=0
        n=len(s)
        while i<n and s[i]==' ':
            i+=1
        sign=1
        if i<n and (s[i]=='+' or s[i]=='-'):
            if s[i]=='-':sign=-1
            i+=1
        while i<n and s[i].isdigit():
            res+=s[i]
            i+=1
        if res=='':
            return 0
        num=int(res)*sign
        return max(-2**31,min(num,2**31-1))