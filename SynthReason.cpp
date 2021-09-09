//Copyright George Wagenknecht 2021
//[WARNING] - Robust information search & manipulation intelligence.
/* the developer is not responsible for the user's intent using this program
 */
// SynthReason v0.9b
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;
string theanswerreadystatic;
string synthreasonword;
string synthcom;
int autothink = 0;
int speedprocessing = 0;
string retain2;
string retain;
int found = 0;
int searchset = 1;
int markerc1 = 0;
string warning = "Warning! points: ";
int markerc2 = 0;
int markerc3 = 0;
int wordpos = 0;
int wordc = 0;
int trade = 0;
float buy = 0;
float sell = 0;
int a = 0;
int b = 0;
int m = 0;
int procnote = 0;
int linereq = 0;
string synthanswer;
int linecount = 0;
int finish = 10;
int anscount = 0;
int ucount, wordcount, wordcountstat;
int fail = 0;
int points = 0;
int question = 0;
int structcount = 0;
int thoughtcount = 0;
char thought[1024][512];
char structure[1024][512];
string testfile = "test.txt";
string lineneeded;
string word;
string textneeded;
string notes;
string fileone = "fileone.txt";
string filetwo = "filetwo.txt";
string chainreason, synthlogictemp;
string magic1 = "", magic2 = "", magic3 = "", magic4 = "", magic5 = "", magic6, magic7, objects, description, actions;
string desname, desobject, desaction, destime, desdescription, desnumber, desreason, desplace, desemotion,
descommand, desbridge, desgame, desconcept;
string desadj = "desadj", desadjp = "desadjp", desadv = "desadv", desadvtime = "desadvtime", desprep = "desprep", desqualities = "desqualities", desverb = "desverb";
string loadfile(string file) {
  string line;
  ifstream textfile;
  textfile.open(file.c_str());
  textneeded.erase();
  while (!textfile.eof()) {
    getline(textfile, line);
    textneeded = textneeded + line;
  }
  char chars[] = ",:<>[]";
  for (unsigned int i = 0; i < strlen(chars); ++i) {
    textneeded.erase(std::remove(textneeded.begin(), textneeded.end(), chars[i]),
      textneeded.end());
  }
  textneeded = textneeded + " END.";
  return textneeded;
}
int filesearch(string segment, string file) {
  ifstream datafile;
  string line;
  int pos = -1;
  int exists = 0;
  datafile.open(file.c_str());
  string wordblock;
  wordblock.erase();
  while (!datafile.eof()) {
    getline(datafile, line);
    if (line == segment) {
      pos = 1;
      break;
    }
  }
  datafile.close();
  if (pos == 1) {
    exists = 1;
  }
  if (pos == 0) {
    exists = 0;
  }
  line.erase();
  return (exists);
}
string processresponsealgbraic(string answerstring, string userinput) {
  string answerstringsegment, theanswer, theanswerready, theanswerreadyreal;
  int ucountpos = 0;
  string userinputcmod = userinput + " ";
  while (ucountpos < userinputcmod.size() - 2) {
    ucount++;
    ucountpos++;
    ucountpos = userinputcmod.find(" ", ucountpos);
  }
  ucount--;
  int segmentstart = 0;
  int segmentend = 0;
  while (segmentend < answerstring.size() - 1) {
    int answered = 0;
    wordcount = 0;
    int completion = 0;
    segmentstart = answerstring.find("[", segmentend);
    segmentend = answerstring.find("]", segmentstart);
    if (segmentstart > -1) {
      answerstringsegment = answerstring.substr(segmentstart, segmentend - segmentstart + 1);
    }
    int pos = 0;
    int posend = 0;
    int lineend = 0;
    lineend = userinput.find(":", lineend + 1);
    while (posend != lineend - 1) {
      posend = userinput.find(" ", pos + 1);
      string word = userinput.substr(pos, posend - pos);
      pos = posend;
      int clip = word.find(" ");
      if (clip == 0) {
        word = word.substr(1, word.size());
      }
      int wordcheck2 = 0;;
      int deviseanswerlimit = answerstringsegment.find(":", wordcheck2);
      while (wordcheck2 < answerstringsegment.size() - 2) {
        wordcheck2 = answerstringsegment.find(word, wordcheck2 + 1);
        int deviseanswerpos = answerstringsegment.find(">", wordcheck2);
        deviseanswerlimit = answerstringsegment.find(":", wordcheck2);
        if (deviseanswerpos > -1 && deviseanswerlimit > -1) {
          if (deviseanswerlimit > deviseanswerpos) {
            theanswer = answerstringsegment.substr(deviseanswerpos + 1,
              deviseanswerlimit -
              deviseanswerpos - 1);
            int notexist = userinput.find(theanswer);
            if (notexist == -1) {
              theanswerready = theanswer + " ";
            }
          }
        }
      }
      int wordcheck = 0;
      if (trade == 0) {
        wordcheck += filesearch(word, "actions.txt");
        wordcheck += filesearch(word, "descriptions.txt");
        string synthcom;
        synthanswer.erase();
        if (userinput.find("?") == -1) {
          if (filesearch(word, "places.txt") == 1) {
            synthanswer = desplace + " is the " + word + "?";
            synthreasonword = word;
          }
          if (filesearch(word, "objects.txt") == 1) {
            synthanswer = desobject + " is " + word + "?";
            synthreasonword = word;
          }
          if (filesearch(word, "actions.txt") == 1) {
            synthanswer = desaction + " does one " + word + "?";
            synthreasonword = word;
          }
          if (filesearch(word, "descriptions.txt") == 1) {
            synthanswer = desdescription + " a " + word + "?";
            synthreasonword = word;
          }
          if (filesearch(word, "reason.txt") == 1) {
            synthanswer = desreason + " does one " + word + "?";
            synthreasonword = word;
          }
          if (filesearch(word, "names.txt") == 1) {
            synthanswer = desobject + " does " + word + " do" + "?";
            synthreasonword = word;
          }
        }
        if (wordcheck > 0) {
          wordcountstat++;
        }
        if (question > -1) {
          if (wordcheck > 0) {
            wordcount++;
            int check = answerstringsegment.find(word);
            if (check > -1) {
              completion++;
            }
          }
        }
      }
    }
    if (answered == 0 || answered == 1) {
      if (completion == wordcount && wordcount > 0) {
        theanswerreadyreal += theanswerready + " ";
        theanswerreadystatic = theanswerready + " ";
        answered = 1;
      }
      if (completion != wordcount && wordcount > 0) {
        fail = 1;
      }
    }
  }
  return theanswerreadyreal;
}
string processlanguage(string userinput) {
  string answerstring;
  markerc1 = 0;
  markerc2 = 0;
  markerc3 = 0;
  int pos = 0;
  int posend = 0;
  int lineend = 0;
  int exists = 1;
  anscount = 0;
  string userinputstack;
  userinputstack = userinputstack + userinput;
  question = userinput.find("?");
  if (question == -1) {
    lineend = userinput.find(":", lineend + 1);
    answerstring = answerstring + "[:";
    while (posend != lineend - 1) {
      posend = userinput.find(" ", pos + 1);
      string word = userinput.substr(pos, posend - pos);
      pos = posend;
      int clip = word.find(" ");
      if (clip == 0) {
        word = word.substr(1, word.size());
      }
      if (trade == 0) {
        exists = 0;
        exists = filesearch(word, "actions.txt");
        if (exists == 1) {
          magic3 = word;
          string requestdescriptors = desaction;
          string requestdescriptorsword = word;
          answerstring = answerstring + requestdescriptors + ">" + word + ":";
          anscount++;
        }
        exists = 0;
        exists = filesearch(word, "descriptions.txt");
        if (exists == 1) {
          description = word;
          string requestdescriptors = desdescription;
          string requestdescriptorsword = word;
          answerstring = answerstring + requestdescriptors + ">" + word + ":";
          anscount++;
        }
      }
      word.erase();
    }
    answerstring.append("]");
  }
  return answerstring;
}
int main(int argc, char * argv[]) {
  system("color 79");
  cout << "the developer is not responsible for the user's intent using this program." << endl;
  string userinputall, userinput, answerstring, theanswerready;
  float temp1;
  int combine;
  float divbuy;
  float divsell;
  string buykey, sellkey;
  int sweep = 0;
  int n = 0;
  desnumber = "count", desobject = "what", destime = "when", desdescription = "describe", desreason = "why", desplace = "where", desemotion = "feel", desaction = "how", descommand = "command", desbridge = "bridge", desconcept = "concept";
  cout << "SynthReason.  v0.9b" << endl;
  int sentstruc = 0;
  ifstream file;
  ifstream::pos_type size;
  char * memblock;
  file.open("knowledgebase.txt", ios:: in | ios::binary | ios::ate);
  if (file.is_open()) {
    size = file.tellg();
    memblock = new char[size];
    file.seekg(0, ios::beg);
    file.read(memblock, size);
    file.close();
    answerstring = memblock;
    delete[] memblock;
  }
  while (0 == 0) {
    cout << endl;

    ofstream fileo;
    string line;
    ofstream textfile4;
    ofstream textfile;
    ucount = 0;
    wordcountstat = 0;
    if (sweep == 0) {
      char * memblock;
      file.open("knowledgebase.txt", ios:: in | ios::binary | ios::ate);
      if (file.is_open()) {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();
        answerstring = memblock;
        delete[] memblock;
      }
      speedprocessing = 0;
      cout << "USER: ";
      getline(cin, userinput);
    }
    if (userinput == "load file") {

      if (argc == 1) {
        userinputall = loadfile("test.txt");
      }
      if (argc > 1) {
        userinputall = loadfile(argv[1]);
      }
      speedprocessing = 1;
      userinput.erase();
      sweep = 1;
    }
    if (userinput == "open new window") {
      system("start main.exe");

    }
    if (userinput == "show answerstring") {
      userinput.erase();
      cout << answerstring;
    }
    if (speedprocessing == 1) {
      answerstring.erase();
    }
    if (userinput == "E41A") {
      userinput.erase();
      while (0 == 0) {
        cout << "ERROR" << endl;
      }
    }
    if (userinput == "E41B") {
      userinput.erase();
      userinputall.erase();
      answerstring.erase();
      textneeded.erase();
      lineneeded.erase();
      notes.erase();
      line.erase();
      word.erase();
    }
    if (userinput == "process info") {
      system("start main \"web.txt\"");
    }
    if (userinput == "show userinputall") {
      userinput.erase();
      cout << userinputall;
      m++;
    }
    if (userinput == "open auto window") {
      system("main \"auto.txt\"");
    }
    if (userinput == "save notes") {
      userinput.erase();
      string line0;
      ofstream textfile0;
      textfile0.open("notes.txt");
      textfile0 << notes;
      textfile0.close();
    }
    if (userinput == "process notes") {
      userinput.erase();
      trade = 0;
      sweep = 1;
      procnote = 1;
    }
    if (sweep == 1) {
      if (procnote == 0) {}
      if (procnote == 1) {
        userinputall = notes + ":";
      }
      if (procnote == 0) {
        b = userinputall.find(".", a + 2);
        userinput = userinputall.substr(a, b - a + 1);
        a = userinputall.find(".", a + 1);
      }
      if (procnote == 1) {
        b = userinputall.find(":", a + 2);
        userinput = userinputall.substr(a, b - a + 1);
        a = userinputall.find(":", a + 1);
      }
    }
    if (a == userinputall.size() - 1) {
      sweep = 0;
      a = 0;
      b = 0;
    }
    if (procnote == 0) {

      int remdot = userinput.find(".");
      if (remdot == 0) {
        userinput = userinput.substr(1, userinput.size() - 1);
      }
      remdot = userinput.find(".");
      if (remdot > 0) {
        userinput = userinput.substr(0, userinput.size() - 1);
      }
    }
    if (procnote == 1) {
      int remdot = userinput.find(":");
      if (remdot == 0) {
        textfile << answerstring;
        textfile.close();
        userinput = userinput.substr(1, userinput.size() - 1);
      }
      remdot = userinput.find(":");
      if (remdot > 0) {
        userinput = userinput.substr(0, userinput.size() - 1);
      }
    }
    question = userinput.find("?");
    if (question > -1) {
      userinput = userinput.substr(0, question);
      userinput.append(" ?");
    }
    if (procnote == 0) {
      userinput = userinput + " :";
    }
    if (sentstruc == 0) {
      answerstring += processlanguage(userinput);
    }
    if (trade == 0 && speedprocessing == 0) {
      if (sentstruc == 0) {
        theanswerready = processresponsealgbraic(answerstring, userinput);
      }
    }
    if (speedprocessing == 1) {
      textfile4.open("knowledgebase.txt", ios::app);
      textfile4 << answerstring;
      textfile4.close();
    }
    n++;
    cout << userinput;
    cout << "[" << theanswerready << "]";
  }
  userinput.erase();
  return 0;
}
