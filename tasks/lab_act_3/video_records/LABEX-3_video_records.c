#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDEO_COUNT 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    int VideoNo;
    char VD_Type[10];
    char VD_Class[20];
    char VD_Title[MAX_TITLE_LENGTH];
    float Rprice;
    float billing;
} VideoRecord;

void enterNewRecord(FILE *file, int *videoCount) {
    VideoRecord record;

    printf("Enter Video Number: ");
    scanf("%d", &record.VideoNo);

    printf("Enter Video Type (Foreign/Local): ");
    scanf("%s", record.VD_Type);

    printf("Enter Video Classification: ");
    scanf("%s", record.VD_Class);

    printf("Enter Video Title: ");
    scanf(" %[^\n]s", record.VD_Title);

    fseek(file, 0, SEEK_SET);
    VideoRecord temp;
    while (fread(&temp, sizeof(VideoRecord), 1, file) == 1) {
        if ((temp.VideoNo == record.VideoNo) && (strcmp(temp.VD_Title, record.VD_Title) == 0) && (strcmp(temp.VD_Type, record.VD_Type) == 0)) {
            printf("Video number already exists.\n");
            return;
        }
    }

    printf("Enter Rental Price: ");
    scanf("%f", &record.Rprice);

    record.billing = 0.0;
    
    fseek(file, 0, SEEK_END);
    fwrite(&record, sizeof(VideoRecord), 1, file);
    (*videoCount)++;
    printf("Record added successfully.\n");
}

void displayRecord(FILE *file, int videoCount) {
    if (videoCount == 0) {
        printf("No records available.\n");
        return;
    }

    VideoRecord record;

    fseek(file, 0, SEEK_SET);
    printf("VideoNo  VD_Type  VD_Class         VD_Title                       Rprice    Billing\n");
    printf("-------------------------------------------------------------------------------\n");

    while (fread(&record, sizeof(VideoRecord), 1, file) == 1) {
        printf("%-8d %-8s %-15s %-30s %-9.2f %-9.2f\n",
               record.VideoNo, record.VD_Type, record.VD_Class,
               record.VD_Title, record.Rprice, record.billing);
    }
}

float calculateBilling(float Rprice, int days) {
    float billing = Rprice * days;

    if (days > 3) {
        int extraDays = days - 3;
        billing += 50.00 * extraDays;
    }

    return billing;
}

void updateBilling(FILE *file, VideoRecord *records, int videoCount) {
    if (videoCount == 0) {
        printf("No records available.\n");
        return;
    }

    int itemNumber, days;
    int found = 0;

    printf("Enter Item Number: ");
    scanf("%d", &itemNumber);

    printf("Enter Number of Days Borrowed: ");
    scanf("%d", &days);

    for (int i = 0; i < videoCount; i++) {
        if (records[i].VideoNo == itemNumber) {
            records[i].billing = calculateBilling(records[i].Rprice, days);

            fseek(file, i * sizeof(VideoRecord), SEEK_SET);
            fwrite(&records[i], sizeof(VideoRecord), 1, file);

            found = 1;
            break;
        }
    }

    if (found) {
        printf("Billing updated successfully.\n");
    } else {
        printf("Video not found.\n");
    }
}

int main() {
    FILE *file = fopen("video_records.dat", "r+");
    if (file == NULL) {
        file = fopen("video_records.dat", "w+");
        if (file == NULL) {
            printf("Failed to open file.\n");
            return 1;
        }
    }

    int videoCount = 0;
    VideoRecord records[MAX_VIDEO_COUNT];

    // Read existing records from the file into the array
    fseek(file, 0, SEEK_SET);
    while (fread(&records[videoCount], sizeof(VideoRecord), 1, file) == 1) {
        videoCount++;
    }

    while (1) {
        int choice;
        printf("\nABC Video Rental Shop\n");
        printf("1. Enter new record\n");
        printf("2. Display the record\n");
        printf("3. Update billing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (videoCount < MAX_VIDEO_COUNT) {
                    enterNewRecord(file, &videoCount);
                } else {
                    printf("Maximum video count reached.\n");
                }
                break;
            case 2:
                displayRecord(file, videoCount);
                break;
            case 3:
                // Refresh the records array with the latest data from the file
                fseek(file, 0, SEEK_SET);
                for (int i = 0; i < videoCount; i++) {
                    fread(&records[i], sizeof(VideoRecord), 1, file);
                }
                updateBilling(file, records, videoCount);
                break;
            case 4:
                fclose(file);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
