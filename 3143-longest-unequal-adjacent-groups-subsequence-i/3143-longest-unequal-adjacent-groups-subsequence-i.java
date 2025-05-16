class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> str = new ArrayList<>();
        List<Integer> index = new ArrayList<>();
        int x = groups[0];
        for(int i=0;i<groups.length;i++)
        {
            if(groups[i]==0 && groups[i]==x)
            {
                index.add(i); x=1;
            }
            else if(groups[i]==1 && groups[i]==x)
            {
                index.add(i); x=0;
            }
        }
        for(int y : index)
        {
            str.add(words[y]);
        }
        return str;
    }
}