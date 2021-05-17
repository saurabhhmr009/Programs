/* Given a string s, find the length of the longest substring without repeating characters.
 */

int lengthOfLongestSubstring(char * s){
    unsigned i, max_length = 0, j = 0;
    unsigned position[96] = {0};

    for(i=0; s[i] != '\0'; i++) {
        if(position[s[i] - 32] > 0) {
            if(max_length < i-j) {
                max_length = i-j;
            }
	    //Like sliding the Window
            if(j < position[s[i] - 32]) {
                j = position[s[i] -32];
            }
        }
        position[s[i] - 32] = i+1;
    }
    
    if(max_length > i-j) {
        return max_length;
    }
    return i-j;
}
