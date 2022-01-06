#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;
#include <vector>
#include <thread>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

char *readFile(char *filename)
{
    FILE *f = fopen(filename, "rt");
    assert(f);
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buffer = (char *)malloc(length + 1);
    buffer[length] = '\0';
    fread(buffer, 1, length, f);
    fclose(f);
    return buffer;
}

void build(char dir[], int jobs)
{
    char *content = readFile("./build.inter");

    std::string complete_file;
    std::string text;

    // Read from the text file
    std::ifstream MyReadFile("./build.inter");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, text))
    {
        // Output the text from the file
        // std::cout << text;

        complete_file.append(text);
    }

    // std::cout << text;
    //std::cout << complete_file << "\n\n";

    std::string str;
    std::string name;

    bool compiler_flag = false;
    bool compiler_flag_comma = false;

    bool setting_value = false;

    std::string CC;

    std::string source_folder;
    std::string include_folder;
    std::string link_libraries;
    std::string flags;
    std::string executable;

    for (size_t i = 0; i < complete_file.length(); i++)
    {
        if (complete_file[i] != ' ')
        {
            if (complete_file[i] != ';')
                str.push_back(complete_file[i]);
            // printf("%c", complete_file[i]);

            if (complete_file[i] == '$')
            {
                compiler_flag = true;
                str = "";
            }

            if (complete_file[i] == ',')
            {
                if (compiler_flag == true)
                {
                    name = str;
                    compiler_flag_comma = true;
                    compiler_flag = false;
                    str = "";
                }
                else
                {
                    name = str;
                    str = "";
                    setting_value = true;
                }
            }

            if (complete_file[i] == ';')
            {
                if (compiler_flag_comma == true)
                {
                    CC = str;
                    name = "";
                    str = "";

                    compiler_flag_comma = false;
                    compiler_flag = false;

                    //std::cout << "CC = " << CC << "\n";
                }
                if (setting_value == true)
                {

                    //std::cout << name << " = " << str << "\n";
                    setting_value = false;

                    // printf("\n%s = %s\n", name, str);
                    if (name == "add_source_folder,")
                        source_folder = str;
                    if (name == "add_include,")
                        include_folder = str;
                    if (name == "link_libraries,")
                        link_libraries = str;
                    if (name == "add_flags,") {
                        flags += " ";
                        flags += str;
                    }
                    if (name == "add_executable,")
                        executable = str;

                    str = "";
                    name = "";
                }
            }

            if (complete_file[i] == ';')
            {
                name = "";
                str = "";
            }

            // str += complete_file[i];
        }
    }

    std::vector<std::string> cmds;
    std::vector<std::string> objs;

    // std::string path = "/path/to/directory";
    for (const auto &entry : fs::directory_iterator(source_folder))
    {
        if(entry.path().extension() != ".o") {
        
        //std::cout << entry.path() << std::endl;

        std::string sus;
        std::string obj;

        sus += CC;
        sus += " ";
        sus += flags;
        sus += " -I";
        sus += include_folder;
        sus += " ";
        sus += link_libraries;
        sus += " -c ";
        sus += entry.path();
        sus += " -o ";
        sus += entry.path();
        sus += ".o";

        obj += entry.path();
        obj += ".o";

        cmds.push_back(sus);
        objs.push_back(obj);
        //std::cout << sus << "\n";

        }
    }

    std::string sus;

    sus += CC;
        sus += " ";
        sus += flags;
        sus += " -I";
        sus += include_folder;
        sus += " ";
        sus += link_libraries;
        sus += " ";
        for (size_t i = 0; i < objs.size(); i++)
        {
            sus += " ";
            sus += objs[i];
        }
        
        sus += " -o ";
        sus += executable;

    bool working = true;
    int jobs_left = cmds.size();

    int current_jobs = 0;
    long unsigned int job_index = 0;

    while (working)
    {
        if(current_jobs != jobs) {
            if(jobs > current_jobs) {
                printf("[%lu / %lu] %s", job_index + 1, cmds.size() + 1, cmds[job_index].c_str());
                system(cmds[job_index].c_str());
                printf(" \e[0;32mdone\e[0m\n");
                job_index++;
                jobs_left--;
            }
        }
        if(jobs_left == 0) break;
    }

    printf("[%lu / %lu] %s", cmds.size() + 1, cmds.size() + 1, sus.c_str());
    system(sus.c_str());
    printf(" \e[0;32mdone\e[0m\n");

    // Close the file
    MyReadFile.close();
}

#pragma GCC diagnostic pop