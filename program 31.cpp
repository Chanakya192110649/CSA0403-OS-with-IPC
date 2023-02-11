#include<stdio.h>
#define MAX_PAGE_FRAMES 100
#define MAX_PAGE_REQUESTS 1000
int pageFrames[MAX_PAGE_FRAMES];
int pageRequests[MAX_PAGE_REQUESTS];
int pageFaults = 0;
int numPageFrames;
int numPageRequests,page_hit;
void initialize() {
    int i;
    for (i = 0; i < numPageFrames; i++) {
        pageFrames[i] = -1;
    }
}
int isInMemory(int page) {
    int i;
    for (i = 0; i < numPageFrames; i++) {
        if (pageFrames[i] == page) {
            return 1;
        }
    }
    return 0;
}
void replacePage(int page) {
    int i;
    for (i = 0; i < numPageFrames - 1; i++) {
        pageFrames[i] = pageFrames[i + 1];
    }
    pageFrames[numPageFrames - 1] = page;
}
int main() {
    int i;
    printf("Enter number of page frames: ");
    scanf("%d", &numPageFrames);
    printf("Enter number of page requests: ");
    scanf("%d", &numPageRequests);
    printf("Enter page requests:\n");
    for (i = 0; i < numPageRequests; i++) {
        scanf("%d", &pageRequests[i]);
    }
    initialize();
    for (i = 0; i < numPageRequests; i++) {
        int page = pageRequests[i];
        if (!isInMemory(page)) {
            pageFaults++;
            if (pageFrames[numPageFrames - 1] != -1) {
                replacePage(page);
            } else {
                pageFrames[numPageFrames - 1] = page;
            }
        }
    }
    printf("Number of page faults: %d\n", pageFaults);
    page_hit=numPageRequests-pageFaults;
    printf("Number of page hit: %d\n",page_hit);
    return 0;
}
