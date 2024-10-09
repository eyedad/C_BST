#include "../include/BST.h"

int main() {
    BST *tree = NULL;
    Data data;

    data.key = 0;
    data.data = "root";
    tree = insert(tree, data);

    FILE *file;
    char line[1024];

    file = fopen("../tests/names", "r");
    if (file == NULL) {
        fprintf(stderr, "ERROR: Cannot open file\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (!feof(file)) {
        i += 1;
        if (fgets(line, sizeof(line), file) != NULL) {
            data.key = order(line);
            data.data = line;
            insert(tree, data);
        } else {
            break;
        }
    }

    collapseTree(tree);
    return 0;
}
