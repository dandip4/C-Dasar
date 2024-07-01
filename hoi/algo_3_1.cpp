// Paket A:
// Pengertian Graph:
// Graph adalah struktur data yang terdiri dari serangkaian simpul (nodes) yang terhubung melalui sisi (edges). Graph digunakan untuk merepresentasikan relasi antar objek.
// Cara Menambahkan Node Baru ke dalam Linked List:
// Untuk menambahkan node baru ke dalam linked list, Anda perlu melakukan beberapa langkah:
// Buat node baru dengan nilai yang diinginkan.
// Atur pointer node baru agar menunjuk ke node berikutnya (atau sebelumnya, tergantung apakah linked list Anda single atau double linked list).
// Atur pointer node sebelumnya untuk menunjuk ke node baru.
// Ilustrasi single linked list dengan minimal 3 node:
// rust
// Copy code
// Head -> [Node1] -> [Node2] -> [Node3] -> NULL
// Paket B:
// Pengertian Binary Search Tree (BST):
// Binary Search Tree adalah struktur data pohon biner di mana setiap node memiliki paling banyak dua anak (left child dan right child), dan setiap node di subtree kiri dari suatu node memiliki nilai kurang dari node tersebut, sedangkan setiap node di subtree kanan memiliki nilai lebih besar dari node tersebut. Ini memungkinkan operasi pencarian, penambahan, dan penghapusan dalam waktu logaritmik.
// Pengertian BFS dan DFS serta Perbedaannya:
// BFS (Breadth-First Search):
// BFS mengunjungi node secara level-by-level, mulai dari node awal dan mengunjungi semua tetangga sebelum mengunjungi tetangga dari tetangga.
// DFS (Depth-First Search):
// DFS mengunjungi node secara rekursif ke bawah sepanjang salah satu cabang pohon sebelum kembali ke node sebelumnya dan menjelajahi cabang lainnya.
// Perbedaan:
// DFS mencari lebih dalam sebelum kembali ke node lain, sedangkan BFS mencari secara melebar.
// BFS menggunakan struktur data antrian (queue) untuk menyimpan node yang akan dikunjungi berikutnya, sedangkan DFS menggunakan struktur data tumpukan (stack) atau rekursi.
// DFS mungkin lebih sederhana untuk diimplementasikan menggunakan rekursi, sementara BFS biasanya menggunakan pendekatan iteratif.
// Paket C:
// Pengertian Array dan Array 2 Dimensi:
// Array: Array adalah struktur data yang terdiri dari kumpulan elemen data dengan tipe yang sama, yang diindeks oleh nomor integer secara berurutan.
// Array 2 Dimensi: Array 2 dimensi adalah array di mana setiap elemen adalah array itu sendiri. Ini membentuk grid atau matriks, di mana setiap elemen dapat diakses dengan menggunakan dua indeks, baris dan kolom.
// Fungsi Bagian pada Tree:
// "Fungsi bagian" pada tree bisa merujuk pada beberapa hal tergantung konteksnya. Berikut adalah beberapa kemungkinan:
// Root (Akar): Node pertama dari tree, merupakan titik awal dari tree.
// Node Internal: Node dalam tree yang memiliki setidaknya satu anak.
// Node Daun (Leaf): Node dalam tree yang tidak memiliki anak.
// Subtree: Sebuah pohon yang merupakan bagian dari pohon utama.
// Cabang (Branch): Edge yang menghubungkan node-node dalam tree