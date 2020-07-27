#include <iostream>
#include <string>
#include <vector>


#include <cstdio>
#include <cstdlib>
#include <getopt.h>

using namespace std;

template <typename Container>
void stringtok(Container& container, const std::string& in, const char * const delimiters = " \t\n") {

   const std::string::size_type len = in.length();
   std::string::size_type i = 0;

   while (i < len) {
      // Eat leading whitespace
      i = in.find_first_not_of(delimiters, i);

      if (i == std::string::npos) {
         return;   // Nothing left but white space
      }

      // Find the end of the token
      std::string::size_type j = in.find_first_of(delimiters, i);

      // Push token
      if (j == std::string::npos) {
         container.push_back(in.substr(i));
         return;
      } 
      else {
         container.push_back(in.substr(i, j-i));
      }

      // Set up for next loop
      i = j + 1;
   }
}

int main (int argc, char** argv) {
   int c;

   vector<string> optVec;
   vector<string>::iterator oi;
   string backend;

   while (1)
   {
      struct option long_options[] =
      {
         {"backend", required_argument, 0, 'b'},
         {"opt",     required_argument, 0, 'o'},
         {0, 0, 0, 0}
      };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long_only (argc, argv, "abc:d:f:",
            long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1){ break; }

      switch (c) {
         case 0:
            /* If this option set a flag, do nothing else now. */
            if (long_options[option_index].flag != 0)
               break;
            printf ("option %s", long_options[option_index].name);
            if (optarg)
               printf (" with arg %s", optarg);
            printf ("\n");
            break;

         case 'o':
            printf ("option -opt with value `%s'\n", optarg);

            stringtok(optVec, optarg, ",");
            for( oi=optVec.begin(); oi != optVec.end(); ++oi ) {
               cout << *oi << ", ";
            }
            cout << endl;
            break;

         case 'b':
            printf ("option -backend with value `%s'\n", optarg);
            backend = optarg;
            break;

         case '?':
            /* getopt_long already printed an error message. */
            break;

         default:
            abort();
      }
   }

   /* Instead of reporting `--verbose'
      and `--brief' as they are encountered,
      we report the final status resulting from them. */

   /* Print any remaining command line arguments (not options). */
   if (optind < argc)
   {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
         printf ("%s ", argv[optind++]);
      putchar ('\n');
   }



   ///////////////// Start processing the vectors here /////////////////////

   for( oi = optVec.begin(); oi != optVec.end(); ++oi ) {
      cout << "Perform optimization : " << *oi << endl;
   }




   exit(0);
}
