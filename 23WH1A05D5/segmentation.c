#include <stdio.h>

int main() {
    int seg_num, seg_base[10], seg_limit[10], i;
    int logical_addr, offset, physical_addr;

    printf("Enter the number of segments: ");
    scanf("%d", &seg_num);

    for (i = 0; i < seg_num; i++) {
        printf("Enter base and limit for segment %d:\n", i);
        printf("Base: ");
        scanf("%d", &seg_base[i]);
        printf("Limit: ");
        scanf("%d", &seg_limit[i]);
    }

    int seg_id;
    printf("Enter segment number: ");
    scanf("%d", &seg_id);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (offset < seg_limit[seg_id]) {
        physical_addr = seg_base[seg_id] + offset;
        printf("Physical Address: %d\n", physical_addr);
    } else {
        printf("Segmentation Fault: Offset exceeds the segment limit.\n");
    }

    return 0;
}

