#include <stdio.h>

int main() {
    int bucket_size, rate, n, i;
    int bucket = 0, packet;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("\nEnter packet size %d: ", i);
        scanf("%d", &packet);

        if(bucket + packet <= bucket_size) {
            bucket += packet;
            printf("Packet accepted, bucket = %d\n", bucket);
        } else {
            printf("Packet dropped\n");
        }

        if(bucket < rate)
            bucket = 0;
        else
            bucket -= rate;

        printf("After sending, bucket = %d\n", bucket);
    }

    return 0;
}