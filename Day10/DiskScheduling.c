#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_REQUESTS 20

int size;

void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int cur_track, distance;

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = fabs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }

    printf("\nTotal distance: %d\n", seek_count);

    printf("SEQUENCE:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d -> ", arr[i]);
    }
    printf("end of sequence\n");
}

void SCAN(int arr[], int head, char *direction, int cylinder_range_start, int cylinder_range_end)
{
    int flag = 0, seek_count = 0;
    int distance, cur_track, left[MAX_REQUESTS], right[MAX_REQUESTS];
    int left_size = 0, right_size = 0;
    int seek_sequence[MAX_REQUESTS * 2];

    if (strcmp(direction, "left") == 0)
        left[left_size++] = cylinder_range_start;
    else if (strcmp(direction, "right") == 0)
        right[right_size++] = cylinder_range_end;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    for (int i = 0; i < left_size - 1; i++)
    {
        for (int j = i + 1; j < left_size; j++)
        {
            if (left[i] > left[j])
            {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++)
    {
        for (int j = i + 1; j < right_size; j++)
        {
            if (right[i] > right[j])
            {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    int run = 2;
    while (run--)
    {
        if (strcmp(direction, "left") == 0)
        {
            for (int i = left_size - 1; i >= 0; i--)
            {
                cur_track = left[i];
                seek_sequence[flag++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "right";
        }
        else if (strcmp(direction, "right") == 0)
        {
            for (int i = 0; i < right_size; i++)
            {
                cur_track = right[i];
                seek_sequence[flag++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = "left";
        }
    }

    printf("\nTotal distance: %d\n", seek_count);
    printf("SEQUENCE:\n");

    for (int i = 0; i < left_size + right_size; i++)
    {
        printf("%d -> ", seek_sequence[i]);
    }
    printf("end of sequence\n");
}

void CSCAN(int arr[], int head, int cylinder_range_start, int cylinder_range_end)
{
    int seek_count = 0;
    int distance, cur_track;
    int left[MAX_REQUESTS], right[MAX_REQUESTS];
    int left_size = 0, right_size = 0;
    int seek_sequence[MAX_REQUESTS * 2];

    left[left_size++] = cylinder_range_start;
    right[right_size++] = cylinder_range_end;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    for (int i = 0; i < left_size - 1; i++)
    {
        for (int j = i + 1; j < left_size; j++)
        {
            if (left[i] > left[j])
            {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++)
    {
        for (int j = i + 1; j < right_size; j++)
        {
            if (right[i] > right[j])
            {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_size; i++)
    {
        cur_track = right[i];
        seek_sequence[i] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    head = 0;
    seek_count += (cylinder_range_end - cylinder_range_start);

    for (int i = 0; i < left_size; i++)
    {
        cur_track = left[i];
        seek_sequence[right_size + i] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    printf("\nTotal distance: %d\n", seek_count);
    printf("SEQUENCE:\n");

    for (int i = 0; i < right_size + left_size; i++)
    {
        printf("%d -> ", seek_sequence[i]);
    }
    printf("end of sequence\n");
}

int main()
{
    int ch, head, arr[MAX_REQUESTS];
    char direction[10];
    int cylinder_range_start, cylinder_range_end;
    
    printf ("MENU OF OPERATIONS:\n1.FCFS  2. SCAN  3. C-SCAN\n");
    
    do
    {
        printf("\nEnter your option: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch) {
			case 1:
			{
				printf("Enter head value: ");
				scanf("%d", &head);
				printf("Enter the number of values: ");
				scanf("%d", &size);
				printf("Enter the values: ");
				for (int i = 0; i < size; i++)
				{ scanf("%d", &arr[i]); }
				
				FCFS(arr, head);

				break;
			}

			case 2:
			{
				printf("Enter head value: ");
				scanf("%d", &head);
				printf("Enter the number of values: ");
				scanf("%d", &size);
				printf("Enter the values: ");
				for (int i = 0; i < size; i++)
				{ scanf("%d", &arr[i]); }

				printf("Enter the direction (left/right): ");
				scanf("%s", direction);
				printf("Enter the start and end cylinders: ");
				scanf("%d%d", &cylinder_range_start, &cylinder_range_end);
				
				SCAN(arr, head, direction, cylinder_range_start, cylinder_range_end);

				break;
			}

			case 3:
			{
				printf("Enter head value: ");
				scanf("%d", &head);
				printf("Enter the number of values: ");
				scanf("%d", &size);
				printf("Enter the values: ");
				for (int i = 0; i < size; i++)
				{ scanf("%d", &arr[i]); }

				printf("Enter the start and end cylinders: ");
				scanf("%d%d", &cylinder_range_start, &cylinder_range_end);
				
				CSCAN(arr, head, cylinder_range_start, cylinder_range_end);

				break;
			}
			   
			case 4:
			{
				printf("Exiting program...\n");
				return 0;
			}
			   
			}

			} while (ch != 4);

    return 0;
}
