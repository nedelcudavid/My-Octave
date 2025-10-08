#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sum;
    int n, m;
    int **el;
} mat_info;

mat_info *realloc_mat(int size, int old_size, mat_info *mat_array)    
{
    if (size == 0) {
        free(mat_array);
        return (mat_info*)malloc(sizeof(mat_info));
    }

    mat_info *new_mat = (mat_info *)malloc(size * sizeof(mat_info));

    for (int i = 0; i < old_size; ++i) {
        new_mat[i] = mat_array[i];
    }

    return new_mat;
}

void add_matrix(mat_info **mat_array, int *nr_total)
{
    (*nr_total)++;
    mat_info new_mat;
    new_mat.sum = 0;

    scanf("%d %d", &new_mat.n, &new_mat.m);

    new_mat.el = malloc(sizeof(mat_info*) * new_mat.n);
    for (int i = 0; i < new_mat.n; i++) {
        new_mat.el[i] = malloc(sizeof(mat_info) * new_mat.m);
    }

    for (int i = 0; i < new_mat.n; i++) {
        for (int j = 0; j < new_mat.m; j++) {
            scanf("%d", &new_mat.el[i][j]);
            new_mat.sum += new_mat.el[i][j];
        }
    }

    *mat_array = realloc_mat((*nr_total - 1), (*nr_total - 2), *mat_array);
    *((*mat_array) + (*nr_total - 1)) = new_mat;
}

void dimensions(mat_info *mat_array, int nr_total)
{
    int index;
    scanf("%d", &index);
    
    if (index >= nr_total) {
        printf("No matrix with the given index");
        printf("\n");
    } else {
        printf("%d " "%d", mat_array[index].n, mat_array[index].m);
        printf("\n");
    }
}

void display(mat_info *mat_array, int nr_total)
{
    int index, i, j;
    scanf("%d", &index);
    
    if (index >= nr_total) {
        printf("No matrix with the given index");
        printf("\n");
    } else {
        for (i = 0; i < mat_array[index].n; i++) {
            for (j = 0; j < mat_array[index].m; j++) {
                printf("%d ", mat_array[index].el[i][j]);
            }
        printf("\n");
        }
    }
}

void redimension(mat_info **mat_array, int *nr_total)
{
    int n, m, index, sum = 0;
    int **new_mat;
    scanf("%d", &index);
    
    if (index >= *nr_total) {
        printf("No matrix with the given index");
    }

    scanf("%d", &n);
    int linii[n];
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &linii[i]);
    }

    scanf("%d", &m);
    int coloane[m];
    
    for (int i = 0; i < m; ++i) {
        scanf("%d", &coloane[i]);
    }

    new_mat = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        new_mat[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_mat[i][j] = (*mat_array)[index].el[linii[i]][coloane[j]];
            sum += new_mat[i][j] % 1007;
        }
    }

    (*mat_array)[index].sum = sum;
    (*mat_array)[index].n = n;
    (*mat_array)[index].m = m;
    (*mat_array)[index].el = new_mat;
}

void multiplication(mat_info **mat_array, int *nr_total)
{
    int index1, index2, i, j;
    scanf("%d", &index1);
    scanf("%d", &index2);

    if (index1 >= (*nr_total) || index2 >= (*nr_total)) {
        printf("No matrix with the given index");
        printf("\n");
    } else {
        if ((*mat_array)[index1].m != (*mat_array)[index2].n) {
            printf("Cannot perform matrix multiplication");
            printf("\n");
        } else {
            int k, xresult[(*mat_array)[index1].n][(*mat_array)[index2].m];

            for (i = 0; i < (*mat_array)[index1].n; i++) {
                for (j = 0; j < (*mat_array)[index2].m; j++) {
                    xresult[i][j] = 0;
                    
                    for (k = 0; k < (*mat_array)[index1].m; k++) {
                        xresult[i][j] = xresult[i][j] + (*mat_array)[index1].el[i][k] * (*mat_array)[index2].el[k][j];
                    }
                }
            }

            (*nr_total)++;
            (*mat_array)[*nr_total - 1].sum = 0;
            *mat_array = realloc_mat(*nr_total, *nr_total - 1, *mat_array);
            (*mat_array)[*nr_total - 1].n = (*mat_array)[index1].n;
            (*mat_array)[*nr_total - 1].m = (*mat_array)[index2].m;
            (*mat_array)[*nr_total - 1].el = (int **)malloc((*mat_array)[*nr_total - 1].n * sizeof(int *));
            
            for (i = 0; i < (*mat_array)[*nr_total - 1].n; i++) {
                (*mat_array)[*nr_total - 1].el[i] = (int *)malloc((*mat_array)[*nr_total - 1].m * sizeof(int));
            }

            for (i = 0; i < (*mat_array)[*nr_total - 1].n; i++) {
                for (j = 0; j < (*mat_array)[*nr_total - 1].m; j++) {
                    (*mat_array)[*nr_total - 1].el[i][j] = xresult[i][j];
                    (*mat_array)[*nr_total - 1].sum = ((*mat_array)[*nr_total - 1].sum + (*mat_array)[*nr_total - 1].el[i][j]) % 1007;
                    if ((*mat_array)[*nr_total - 1].sum < 0) {
                        while ((*mat_array)[*nr_total - 1].sum < 0) {
                            (*mat_array)[*nr_total - 1].sum += 1007;
                        }
                    }
                }
            }
        }
    }
}

void minfo_swap(mat_info *m1, mat_info *m2)
{
    int int_aux;
    int **mat_aux;

    int_aux = m2->sum;
    m2->sum = m1->sum;
    m1->sum = int_aux;

    int_aux = m2->n;
    m2->n = m1->n;
    m1->n = int_aux;

    int_aux = m2->m;
    m2->m = m1->m;
    m1->m = int_aux;

    mat_aux = m2->el;
    m2->el = m1->el;
    m1->el = mat_aux;
}

void sort(mat_info *mat_array, int nr_total)
{
    int i, j, aux;
    
    for (i = 0; i < nr_total - 1; i++) {
        for (j = i + 1; j < nr_total; j++) {
            if (mat_array[i].sum > mat_array[j].sum) {
                minfo_swap(&mat_array[i], &mat_array[j]);
            }
        }
    }
}

void transpose(mat_info *mat_array, int nr_total)
{
    int i, j, aux, index;
    scanf("%d", &index);
    
    if (index >= nr_total) {
        printf("No matrix with the given index");
        printf("\n");
    } else {
        for (i = 0; i < mat_array[index].n; i++) {
            for (j = i + 1; j < mat_array[index].n; j++) {
                aux = mat_array[index].el[i][j];
                mat_array[index].el[i][j] = mat_array[index].el[j][i];
                mat_array[index].el[j][i] = aux;
            }
        }
    }
}

void free_mat(mat_info **mat) {
    for (int i = 0; i < (*mat)->n; i++) {
        free((*mat)->el[i]);
    }
    free(*mat);
    *mat = NULL;
}

void mat_free(mat_info *mat_array, int *nr_total)
{
    int index, i, j;
    scanf("%d", &index);
   
    if (index >= *nr_total) {
        printf("No matrix with the given index");
        printf("\n");
    } else { 
        free_mat(&mat_array[index]);
        int toDelete = -1;
        for (int i = 0; i < *nr_total; i++) {
            if((mat_array + i) == NULL) {
                toDelete = i;
            }
        }

        for (int i = toDelete; i < *nr_total - 1; i++) {
            mat_array[i] = mat_array[i + 1]; 
        }
        (*nr_total)--;
    }
}

int main()
{
    char input;
    mat_info *mat_array = (mat_info *)malloc(0);
    int nr_total = 0;

    while (1) {
        scanf("%c", &input);
        int check = 0;
        
            if (input == 'L') {
                add_matrix(&mat_array, &nr_total);
                check = 1;
                continue;
            }

            if (input == 'D') {
                check = 1;
                dimensions(mat_array, nr_total);
                continue;
            }

            if (input == 'P') {
                check = 1;
                display(mat_array, nr_total);
                continue;
            }

            if (input == 'C') {
                check = 1;
                redimension(&mat_array, &nr_total);
                continue;
            }

            if (input == 'M') {
                check = 1;
                multiplication(&mat_array, &nr_total);
                continue;
            }

            if (input == 'O') {
                check = 1;
                sort(mat_array, nr_total);
                continue;
            }

            if (input == 'T') {
                check = 1;
                transpose(mat_array, nr_total);
                continue;
            }

            if (input == 'F')  {
                check = 1;
                mat_free(mat_array, &nr_total);
                continue;
            } 

            if (input == 'Q') {
                check = 0;
                break;
            }
        
            if (input != 'L' || input != 'D' || input != 'P' || input != 'C' || input != 'M' || input != 'O' || input != 'T' || input != 'F' || input != 'Q') {
                if (input != 0xA)
                printf("Unrecognized command \n");
            }
    }

    return 0;
}