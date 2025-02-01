// #include "minilibx/mlx.h"
// #define WIDTH 1000
// #define HEIGTH 800
// #include <stdlib.h>
// int main()
// {
//     void    *mlx_connection;
//     void    *mlx_window;

//     mlx_connection = mlx_init();
//     mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGTH, "Ali");
//     for(int y = HEIGTH * 0.1; y < HEIGTH * 0.9; ++y)
//     {
//         for(int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
//         {
//             mlx_pixel_put(mlx_connection , mlx_window, x, y, rand() % 0x1000000);
        
//         }

//     }
//     mlx_string_put(mlx_connection, mlx_window, WIDTH * 0.8, HEIGTH * 0.95, rand() % 0x1000000, "Ali test");
//     mlx_loop(mlx_connection);
// }
// #include "minilibx/mlx.h"
// #include <math.h>
// #define WIDTH 1000
// #define HEIGHT 800

// int main()
// {
//     void    *mlx = mlx_init();
//     void    *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Gradient");

//     // Horizontal gradient from red to blue
//     for (int y = 0; y < HEIGHT; y++) {
//         for (int x = 0; x < WIDTH; x++) {
//             int r = 255 * x / WIDTH;
//             int b = 255 * (WIDTH - x) / WIDTH;
//             mlx_pixel_put(mlx, win, x, y, (r << 16) | b);
//         }
//     }
//     mlx_loop(mlx);
// }
// #include "minilibx/mlx.h"
// #define WIDTH 1000
// #define HEIGHT 800

// int mouse_handler(int x, int y, void *param)
// {
//     void *mlx = ((void **)param)[0];
//     void *win = ((void **)param)[1];
    
//     // Generate color based on mouse position
//     int r = 255 * x / WIDTH;
//     int g = 255 * y / HEIGHT;
//     int b = 255 * (x + y) / (WIDTH + HEIGHT);
    
//     mlx_clear_window(mlx, win);
//     mlx_string_put(mlx, win, WIDTH/2 - 40, HEIGHT/2, (r << 16) | (g << 8) | b, "INTERACTIVE!");
//     return 0;
// }

// int main()
// {
//     void    *mlx = mlx_init();
//     void    *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Interactive");
//     void    *params[2] = {mlx, win};

//     mlx_hook(win, 6, 1L<<6, mouse_handler, params);
//     mlx_loop(mlx);
// }
// #include "minilibx/mlx.h"
// #include <stdlib.h>
// #define WIDTH 1500
// #define HEIGHT 1500

// typedef struct s_data {
//     void    *mlx;
//     void    *win;
//     char    matrix[WIDTH][HEIGHT];
// } t_data;

// void update_matrix(t_data *data)
// {
//     // Move characters down and create new random characters
//     for (int x = 0; x < WIDTH; x++) {
//         for (int y = HEIGHT-1; y > 0; y--) {
//             data->matrix[x][y] = data->matrix[x][y-1];
//         }
//         data->matrix[x][0] = (rand() % 2) ? (rand() % 94) + 33 : ' ';
//     }
// }

// int draw_matrix(t_data *data)
// {
//     mlx_clear_window(data->mlx, data->win);
//     for (int x = 0; x < WIDTH; x += 10) {
//         for (int y = 0; y < HEIGHT; y += 20) {
//             int color = 0x00FF00 | ((y * 255 / HEIGHT) << 24);
//             mlx_string_put(data->mlx, data->win, x, y, color, (char[]){data->matrix[x][y], 0});
//         }
//     }
//     update_matrix(data);
//     return 0;
// }

// int main()
// {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Matrix");
    
//     // Initialize matrix with random characters
//     for (int x = 0; x < WIDTH; x++)
//         for (int y = 0; y < HEIGHT; y++)
//             data.matrix[x][y] = ' ';
    
//     mlx_loop_hook(data.mlx, draw_matrix, &data);
//     mlx_loop(data.mlx);
// }

// #include "minilibx/mlx.h"
// #define WIDTH 1000
// #define HEIGHT 800

// void modern_design(void *mlx, void *win)
// {
//     // Background gradient
//     for (int y = 0; y < HEIGHT; y++) {
//         int shade = 255 * y / HEIGHT;
//         for (int x = 0; x < WIDTH; x++) {
//             mlx_pixel_put(mlx, win, x, y, (shade << 16) | (shade << 8) | shade);
//         }
//     }

//     // Floating card
//     int card_w = WIDTH/2;
//     int card_h = HEIGHT/2;
//     for (int y = HEIGHT/4; y < HEIGHT/4*3; y++) {
//         for (int x = WIDTH/4; x < WIDTH/4*3; x++) {
//             int color = 0x2E3440; // Dark blue-gray
//             if (x == WIDTH/4 || x == WIDTH/4*3-1 || y == HEIGHT/4 || y == HEIGHT/4*3-1)
//                 color = 0x88C0D0; // Light blue border
//             mlx_pixel_put(mlx, win, x, y, color);
//         }
//     }

//     // Modern text
//     mlx_string_put(mlx, win, WIDTH/2 - 40, HEIGHT/2, 0x88C0D0, "MODERN UI");
// }

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Modern Design");
    
//     modern_design(mlx, win);
//     mlx_loop(mlx);
// }

// #include "minilibx/mlx.h"
// #define WIDTH 800
// #define HEIGHT 600
// #include <stdio.h>
// int main()
// {
//     void    *mlx = mlx_init();
//     void    *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Image Demo");
    
//     // 1. Load image
//     int img_width;
//     int img_height;
//     void    *img = mlx_xpm_file_to_image(mlx, "pic.xpm", &img_width, &img_height);
    
//     // 2. Error check
//     if (!img) {
//         mlx_destroy_window(mlx, win);
//         return (printf("Error: Failed to load image\n"), 1);
//     }
    
//     // 3. Display image at position (x, y)
//     mlx_put_image_to_window(mlx, win, img, 1, 1);
    
//     mlx_loop(mlx);
//     return 0;
// }
#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define TILE_SIZE 32  // Each tile is 32x32 pixels

int main()
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width, img_height;

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (printf("Error: MLX initialization failed\n"), 1);

    // Create window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Map with Images");
    if (!win)
        return (printf("Error: Failed to create window\n"), 1);

    // Load image
    img = mlx_xpm_file_to_image(mlx, "pic.xpm", &img_width, &img_height);
    if (!img)
    {
        mlx_destroy_window(mlx, win);
        return (printf("Error: Failed to load image\n"), 1);
    }

    // Ensure image size matches TILE_SIZE
    if (img_width != TILE_SIZE || img_height != TILE_SIZE)
    {
        mlx_destroy_image(mlx, img);
        mlx_destroy_window(mlx, win);
        return (printf("Error: Image size must be %dx%d\n", TILE_SIZE, TILE_SIZE), 1);
    }

    // Define a simple map (1 = wall, 0 = empty)
    int map_rows = HEIGHT / TILE_SIZE;
    int map_cols = WIDTH / TILE_SIZE;

    int map[map_rows][map_cols];

    // Initialize map (border walls, empty inside)
    for (int y = 0; y < map_rows; y++)
    {
        for (int x = 0; x < map_cols; x++)
        {
            if (x == 0 || x == map_cols - 1 || y == 0 || y == map_rows - 1)
                map[y][x] = 1;  // Walls
            else
                map[y][x] = 0;  // Empty space
        }
    }

    // Draw the map
    for (int y = 0; y < map_rows; y++)
    {
        for (int x = 0; x < map_cols; x++)
        {
            if (map[y][x] == 1)
                mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }

    // MLX loop
    mlx_loop(mlx);

    // Clean up (MLX does not exit until window is closed)
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    return 0;
}
