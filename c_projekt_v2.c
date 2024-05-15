#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERZIO "alap.v2"

char c[] =
{
    "#include <stdio.h>\n\n"
    "int main() {\n"
    "    printf(\"Hello World!\\n\");\n"
    "    return 0;\n"
    "}\n"
};

char python[] =
{
    "def main():\n\n"
    "    print(\"Hello World!\\n\")\n"
    "          \n"
    "if __name__ == \"__main\\n\":\n"
    "   main()\n"
};

char java[] =
{
    "public class Main {\n\n"
    " public static void main(String[] args) {\n"
    "  System.out.println(\"Hello World!\\n\");\n"
    "   }\n"
    "}\n"
};

void print_help()
{
    printf("Hasznalat: alap <sablon_id> [opcio]\n\n");
    printf("Lehetseges opciok:\n");
    printf("-h, --help     ez a sugo\n");
    printf("-v, --version  verzio informacio\n");
    printf("-stdout        ne hozzon letre forrasfajlt, az eredmenyt irja ki a stdout-ra\n\n");
    printf("Elerheto alap kodok:\n");
    printf("* c       - C forraskod [main.c]\n");
    printf("* python  - Python forraskod [main.py]\n");
    printf("* java    - Java forraskod [Main.java]\n");
}

void generate_source(const char *template, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
        fprintf(file, "%s", template);
        fclose(file);
    }
    else
    {
        printf("Hiba: Nem sikerult letrehozni a(z) %s fajlt\n", filename);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1 || strcmp(argv[1], "alap") != 0)
    {
        print_help();
        return 0;
    }

    if (argc == 3 && (strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "--help") == 0))
    {
        print_help();
    }
    else if (argc == 3 && (strcmp(argv[2], "-v") == 0 || strcmp(argv[2], "--version") == 0))
    {
        printf("%s\n", VERZIO);
    }
    else if (argc >= 3 && argc <= 4)
    {
        if (strcmp(argv[2], "c") == 0)
        {
            generate_source(c, "main.c");
        }
        else if (strcmp(argv[2], "python") == 0)
        {
            generate_source(python, "main.py");
        }
        else if (strcmp(argv[2], "java") == 0)
        {
            generate_source(java, "Main.java");
        }
        else
        {
            printf("Hiba: Ervenytelen sablon azonosito\n");
            return 1;
        }
    }
    else
    {
        printf("Hiba: Ervenytelen parancs\n");
        return 1;
    }

    return 0;
}