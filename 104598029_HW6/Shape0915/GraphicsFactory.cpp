#include "GraphicsFactory.h"

Graphics * GraphicsFactory::buildGraphicsFromFile(const char * fileName){
    string temp;
    int cur_level = 0, level;
    stringstream ss;
    ss << fileContentsAsString(fileName);
    ss >> level;
    ss >> temp;
    while (!ss.fail()){
        if(temp == "Comp") // ss Comp-R(0,0,0,0)
        {
            cur_level++;
            g_s.push(new CompositeGraphics(level));
            ss >> temp; //R(0,0,0,0)
        }
        else{
            if(cur_level == level){
                g_s.push(extractGraphicsFromOneLine(temp,level));
            }
            else{
                cur_level = level;
                compose();
                g_s.push(extractGraphicsFromOneLine(temp,level));
            }
        }
        ss >>level;
        ss >>temp;
    }
    compose();
    return g_s.top();
}

string GraphicsFactory::fileContentsAsString(const char* fileName){
    string temp , contents;
    ifstream input_file;
    int level=0;
    input_file.open(fileName,ios::in);
    while(getline(input_file,temp)){
        while(temp[level] == ' '){
            level++;
        }
        contents += to_string(level/2);
        contents +=" ";
        contents += temp;
        contents += "\n";
        level = 0;
    }
    input_file.close();
    return contents;
}


 Graphics * GraphicsFactory::extractGraphicsFromOneLine(string & contents, int & level){
     Graphics* sg;
     int num[4];
     int i,j; // i is string num. j is array num.
        i=2;
        j=0;
     while ( i < contents.length()){
        if(contents[i]=='-'){
            i++;
            num[j]= atoi(&contents[i])*-1;
            j++;
        }
        else{
            num[j]= atoi(&contents[i]);
            j++;
        }
        i+=2;
    }
    if(contents[0] == 'R'){
        sg = new SimpleGraphics(new Rectangle( num[0] , num[1] , num[2] , num[3] , level));

    }
    if(contents[0] == 'C'){
        sg = new SimpleGraphics(new Circle( num[0] , num[1] , num[2] , level));
    }
    if(contents[0] == 'S'){
        sg = new SimpleGraphics(new Square( num[0] , num[1] , num[2] , level));
    }
    return sg;
 }

 void GraphicsFactory::compose(){
     int level;
     level = g_s.top()->level;
     stack <Graphics *> temp_s;
     while (g_s.top()->level == level){
        temp_s.push(g_s.top());
        g_s.pop();
     }
    while(!temp_s.empty()){
        g_s.top()->add(temp_s.top());
        temp_s.pop();
    }
 }

