# Kuro
A efi image loader 


### Steps to create an EFI disk image
*	 create a file with all zeros  
`dd if=/dev/zero of=<image_name> bs=<int> count=<int> `

* format it using gdisk (follow the help, make sure you have one EFI system partition.
`gdisk <image_name>`

* map the diskimage
`sudo kpartx -av <image_name>`

* format the image (ESP is always FAT32)
`sudo mkfs.fat -F 32 /dev/mapper/<disk_map>`

* mount the partition
`sudo mount /dev/mapper/<disk_map> <mount_point>`

* make EFI boot directory 
`sudo mkdir <mount_point>/EFI/Boot` 

* copy image
`sudo cp <image> <mount_point>/EFI/Boot`

* unmount
`sudo umount <mount_point>`

* clean up
`sudo kpartx -d <image_name>`