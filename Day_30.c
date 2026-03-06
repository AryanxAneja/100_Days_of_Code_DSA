#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int power;
    struct Node* next;
} Node;

Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->power = pow;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node** poly, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    
    if (*poly == NULL || (*poly)->power < pow) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }
    
    Node* curr = *poly;
    while (curr->next != NULL && curr->next->power > pow) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void displayPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->power);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power == poly2->power) {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->power > poly2->power) {
            insertTerm(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->power);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->power);
        poly2 = poly2->next;
    }
    
    return result;
}

void freePolynomial(Node* poly) {
    while (poly != NULL) {
        Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    
    // Create polynomial 1: 5x^3 + 4x^2 + 3x^1
    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 3, 1);
    
    // Create polynomial 2: 2x^3 + 1x^2 + 6x^0
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, 1, 2);
    insertTerm(&poly2, 6, 0);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    Node* result = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(result);
    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}