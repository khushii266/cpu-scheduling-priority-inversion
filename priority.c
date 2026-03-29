#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Clear screen
void clear_screen() {
    system("clear");
}

// Print UI
void display(char *status, char *lock,
             char *p1, char *p2, char *p3) {

    clear_screen();

    printf("=================================================\n");
    printf("            CPU SCHEDULING SIMULATION\n");
    printf("=================================================\n\n");

    printf("Process Information:\n");
    printf("-------------------------------------------------\n");
    printf("P1 (High Priority)    : %s\n", p1);
    printf("P2 (Medium Priority)  : %s\n", p2);
    printf("P3 (Low Priority)     : %s\n\n", p3);

    printf("Resource Information:\n");
    printf("-------------------------------------------------\n");
    printf("Mutex Lock            : %s\n\n", lock);

    printf("System Status:\n");
    printf("-------------------------------------------------\n");
    printf("%s\n", status);

    printf("\n=================================================\n");
}

// Scene 1
void scene1() {
    display("Normal scheduling: high priority process executing.",
            "AVAILABLE",
            "RUNNING",
            "WAITING",
            "WAITING");
    sleep(2);
}

// Scene 2
void scene2() {
    display("Low priority process acquires the resource.",
            "LOCKED (Owner: P3)",
            "WAITING",
            "WAITING",
            "RUNNING");
    sleep(3);
}

// Scene 3 (Priority Inversion)
void scene3() {
    display("High priority process blocked. Medium priority executing.",
            "LOCKED (Owner: P3)",
            "BLOCKED",
            "RUNNING",
            "READY (Holding Lock)");
    sleep(4);
}

// Scene 4 (System Issue)
void scene4() {
    display("System inefficiency detected due to priority inversion.",
            "LOCKED (Owner: P3)",
            "BLOCKED",
            "RUNNING",
            "DELAYED");
    sleep(3);
}

// Scene 5 (Priority Inheritance)
void scene5() {
    display("Priority inheritance applied to low priority process.",
            "LOCKED (Owner: P3, Elevated Priority)",
            "WAITING",
            "WAITING",
            "RUNNING (ELEVATED)");
    sleep(3);

    display("Resource released by low priority process.",
            "AVAILABLE",
            "WAITING",
            "WAITING",
            "COMPLETED");
    sleep(2);

    display("High priority process resumes execution.",
            "AVAILABLE",
            "RUNNING",
            "WAITING",
            "COMPLETED");
    sleep(3);
}

// Scene 6 (Final)
void scene6() {
    display("All processes completed successfully. System stable.",
            "AVAILABLE",
            "COMPLETED",
            "COMPLETED",
            "COMPLETED");
    sleep(3);
}

int main() {
    scene1();
    scene2();
    scene3();
    scene4();
    scene5();
    scene6();
    return 0;
}
