/**************** expand.c ***************
 * Expands string statements such as "a-z"
 * To their full form "abcdefg..."
 *****************************************
 */

 #include <stdio.h>
 
 /** I am interpreting the problem to be case sensitive, so in this implementation,
  *  values "a-Z" would be invalid, as it should be either "a-z" or "A-Z".
  */
void expand(const char s1[], char s2[]){
   int i;   
   int s2i = 0;
   // We will iterate between between position 1 and (len-1) to track the values before and after
   for (i = 1; s1[i+1] != '\0' && s1[i+1] != EOF; i++){
      // Start out checking if the current value is '-'
      if(s1[i] == '-'  && s1[i+1] > s1[i-1]){
         int start = 0;
         int diff = s1[i+1] - s1[i-1] + 1;


         /**
          * I could probably factor a lot of this out, but for the sake of moving on, I will keep it this way
          * On this version.
          */
         // Lowercase
         if(s1[i-1] >= 'a' && s1[i+1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] <= 'z'){
            // If two letters ago we had a "-" and three letters ago we had a lowercase, start one after this letter
            if (i >= 3 && s1[i-2] == '-' && s1[i-3] >= 'a' && s1[i-3] <= 'z')
               start++;
            for (int j = start; j < diff; j++)
               s2[s2i++] = j + s1[i-1];

            // Edge case: if we are at the end, null terminate and return
            if (s1[i+1] == '\0' || s1[i+1] == EOF){
               s2[s2i] = '\0';
               return;
            }   
            // We are at least skipping one place, given there are more values.
            if (s1[i+1] != '\0' && s1[i+1] != EOF)
               i++;
            // Edge case: if there is no proceeding '-', then skip the next character
            if(s1[i+1] != '\0' && s1[i+1] != EOF && s1[i+1] != '-')
               i++;
            
            continue;
         }
         // Capital
         if(s1[i-1] >= 'A' && s1[i+1] >= 'A' && s1[i-1] <= 'Z' && s1[i+1] <= 'Z'){
            if (i >= 3 && s1[i-2] == '-' && s1[i-3] >= 'A' && s1[i-3] <= 'Z')
               start++;
            for (int j = start; j < diff; j++)
               s2[s2i++] = j + + s1[i-1];

            if (s1[i+2] == '\0' || s1[i+2] == EOF){
               s2[s2i] = '\0';
               return;
            }   
            if (s1[i+1] != '\0' && s1[i+1] != EOF)
               i++;
            if(s1[i+1] != '\0' && s1[i+1] != EOF && s1[i+1] != '-')
               i++;
            
            continue;
         }
         // Numbers
         if(s1[i-1] >= '0' && s1[i+1] >= '0' && s1[i-1] <= '9' && s1[i+1] <= '9'){
            if (i >= 3 && s1[i-2] == '-' && s1[i-3] >= '0' && s1[i-3] <= '9')
               start++;
            for (int j = start; j < diff; j++)
               s2[s2i++] = j + + s1[i-1];

            if (s1[i+1] == '\0' || s1[i+1] == EOF){
               s2[s2i] = '\0';
               return;
            }   
            if (s1[i+1] != '\0' && s1[i+1] != EOF)
               i++;
            if(s1[i+1] != '\0' && s1[i+1] != EOF && s1[i+1] != '-')
               i++;
            continue;
         }
      }
      // If it's still in the loop, that means we can read the first value
      s2[s2i++] = s1[i-1];
   }
   // Now read whatever is left
   s2[s2i] = s1[i];
   s2[s2i+1] = '\0';
}

 int main(){
   char s1[] = "hia-z howdy0-5-9a-c -zA-Z";
   char s2[2000];
   expand(s1, s2);

   printf("Original: %s\nExpanded: %s\n", s1, s2);
    return 0;
 }