#include "icons.h"

// takes battery percent (integer) as input and prints battery icon
void iconBattery(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, byte percent)
{
    display.drawRect(8, 4, 12, 7, GxEPD_BLACK);
    display.drawRect(6, 5, 2, 5, GxEPD_BLACK);

    if (percent >= 95) // Full
        display.fillRect(9, 4, 10, 6, GxEPD_BLACK);
    else if (percent >= 85 && percent < 95) // ful-Med
        display.fillRect(10, 4, 9, 6, GxEPD_BLACK);
    else if (percent > 65 && percent < 85) // Med
        display.fillRect(11, 4, 9, 6, GxEPD_BLACK);
    else if (percent > 40 && percent <= 65) // half
        display.fillRect(13, 4, 7, 6, GxEPD_BLACK);
    else if (percent > 20 && percent <= 40) // low
        display.fillRect(15, 4, 5, 6, GxEPD_BLACK);
    else if (percent > 8 && percent <= 20) // critical-low
        display.fillRect(16, 5, 3, 5, GxEPD_RED);
    else
    { // near empty
        display.drawRect(8, 4, 12, 7, GxEPD_RED);
        display.drawRect(6, 5, 2, 5, GxEPD_RED);
    }
}

void fillEllipsis(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c)
{
    for (int yi = -h; yi <= h; yi++)
    {
        for (int xi = -w; xi <= w; xi++)
        {
            if (xi * xi * h * h + yi * yi * w * w <= h * h * w * w)
                display.writePixel(x + xi, y + yi, c);
        }
    }
}

// Copy all the remaining icon function implementations from the original file here
// ...existing icon function implementations...

// Separate the icons in future update to separate file
void iconCloud(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t r)
{
    // top circle
    display.fillCircle(x, y, r, GxEPD_BLACK);
    // left circle
    display.fillCircle(x - r * 0.85, y + r * 0.8, r * 0.85, GxEPD_BLACK);
    // right circle
    display.fillCircle(x + r * 1.1, y + r * 0.8, r * 0.85, GxEPD_BLACK);
    // rectangle
    display.fillRect(x - r * 0.85, y + r * 0.8, (x + r * 1.1) - (x - r * 0.85), r * 0.9, GxEPD_BLACK);

    // top circle
    float offset = 0.8;
    display.fillCircle(x, y, r * offset, GxEPD_WHITE);
    // left circle
    display.fillCircle(x - r * 0.85, y + r * 0.8, r * 0.85 * offset, GxEPD_WHITE);
    // right circle
    display.fillCircle(x + r * 1.1, y + r * 0.8, r * 0.85 * offset, GxEPD_WHITE);
    // rectangle
    display.fillRect(x - r * 0.85, y + r * 0.7, (x + r * 1.1) - (x - r * 0.85), r * offset, GxEPD_WHITE);
}

void iconSun(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t r)
{
    display.drawLine(x - r * 1.75, y, x + r * 1.75, y, GxEPD_BLACK);
    display.drawLine(x, y - r * 1.75, x, y + r * 1.75, GxEPD_BLACK);
    display.drawLine(x - r * 1.25, y - r * 1.25, x + r * 1.25, y + r * 1.25, GxEPD_BLACK);
    display.drawLine(x - r * 1.25, y + r * 1.25, x + r * 1.25, y - r * 1.25, GxEPD_BLACK);
    display.fillCircle(x, y, r * 1.2, GxEPD_WHITE);
    display.fillCircle(x, y, r, GxEPD_BLACK);
    float offset = 0.9;
    display.fillCircle(x, y, r * offset, GxEPD_RED);
}

void iconMoon(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t r)
{
    float offset = 0.9;
    display.fillCircle(x, y, r, GxEPD_BLACK);
    display.fillCircle(x, y, r * offset, GxEPD_RED);
    display.fillCircle(x + r, y - r, r, GxEPD_BLACK);
    display.fillCircle(x + r, y - r, r * offset, GxEPD_WHITE);
    display.fillRect(x, y - r * 2, r * 2.5, r, GxEPD_WHITE);
    display.fillRect(x + r + 1, y - r, r * 1.5, r * 1.5, GxEPD_WHITE);
}

void iconClearDay(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconSun(display, x + s / 2, y + s / 2, s / 5);
}

void iconClearNight(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconMoon(display, x + s / 2, y + s / 2, s / 5);
}

void iconRain(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.275, y + s * 0.6, s / 2.5, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    for (int i = 0; i <= s * 0.1; i++)
    {
        display.fillCircle(x + s * 0.4 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
        display.fillCircle(x + s * 0.6 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
    for (int i = 0; i <= s * 0.16; i++)
    {
        display.fillCircle(x + s * 0.5 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
}

void iconSleet(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.275, y + s * 0.6, s / 2.5, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    for (int i = 0; i <= s * 0.1; i++)
    {
        if (i < 1 || i > s * 0.1 * 0.5)
        {
            display.fillCircle(x + s * 0.4 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
            display.fillCircle(x + s * 0.6 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
        }
    }
    for (int i = 0; i <= s * 0.16; i++)
    {
        if (i < s * 0.16 * 0.5 || i > s * 0.16 * 0.8)
            display.fillCircle(x + s * 0.5 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
}

void iconSnow(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.275, y + s * 0.6, s / 2.5, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    display.fillCircle(x + s / 2.75, y + s * 0.7, s * 0.02, GxEPD_BLACK);
    display.fillCircle(x + s / 1.75, y + s * 0.7, s * 0.02, GxEPD_BLACK);

    display.fillCircle(x + s / 2.75, y + s * 0.8, s * 0.02, GxEPD_BLACK);
    display.fillCircle(x + s / 1.75, y + s * 0.8, s * 0.02, GxEPD_BLACK);

    display.fillCircle(x + s / 2.15, y + s * 0.65, s * 0.02, GxEPD_BLACK);
    display.fillCircle(x + s / 2.15, y + s * 0.75, s * 0.02, GxEPD_BLACK);
    display.fillCircle(x + s / 2.15, y + s * 0.85, s * 0.02, GxEPD_BLACK);
}

void iconWind(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    float offset = 0.8;
    for (int i = 0; i <= s * 0.7; i++)
    {
        if (i < s * 0.6)
            display.fillCircle(x + s * 0.15 + i, y + s * 0.4, s * 0.02, GxEPD_BLACK);
        if (i < s * 0.5)
            display.fillCircle(x + s * 0.1 + i, y + s * 0.5, s * 0.02, GxEPD_BLACK);
        if (i < s * 0.2)
            display.fillCircle(x + s * 0.7 + i, y + s * 0.5, s * 0.02, GxEPD_BLACK);
        if (i < s * 0.6)
            display.fillCircle(x + s * 0.2 + i, y + s * 0.6, s * 0.02, GxEPD_BLACK);
    }
}

void iconFog(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.1, y + s * 0.55, s * 0.75, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    for (int i = 0; i <= s * 0.7; i++)
    {
        display.fillCircle(x + s * 0.1 + i, y + s * 0.6, s * 0.02, GxEPD_BLACK);
        display.fillCircle(x + s * 0.2 + i, y + s * 0.7, s * 0.02, GxEPD_BLACK);
        display.fillCircle(x + s * 0.15 + i, y + s * 0.8, s * 0.02, GxEPD_BLACK);
    }
}

void iconCloudy(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + (s / 4) * 3, y + s / 4, s / 10);
    iconCloud(display, x + s / 2.1, y + s / 2.2, s / 5);
}

void iconCloudyDay(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconSun(display, x + (s / 3) * 2, y + s / 2.5, s / 6);
    iconCloud(display, x + s / 2.2, y + s / 2.2, s / 5);
}

void iconCloudyNight(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconMoon(display, x + (s / 3) * 2, y + s / 3, s / 6);
    iconCloud(display, x + s / 2.2, y + s / 2.2, s / 5);
}

void iconHail(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.275, y + s * 0.6, s / 2.5, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    for (int i = 0; i <= s * 0.1; i++)
    {
        if (i < s * 0.1 * 0.5 || i == s * 0.1)
        {
            display.fillCircle(x + s * 0.4 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
            display.fillCircle(x + s * 0.6 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
        }
    }
    for (int i = 0; i <= s * 0.16; i++)
    {
        if (i < s * 0.16 * 0.7 || i == s * 0.16)
            display.fillCircle(x + s * 0.5 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
}

void iconThunderstorm(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    iconCloud(display, x + s / 2.2, y + s / 2.5, s / 5);
    display.fillRect(x + s * 0.275, y + s * 0.6, s / 2.5, s / 5, GxEPD_WHITE);

    float offset = 0.8;
    for (int i = 0; i <= s * 0.1; i++)
    {
        display.fillCircle(x + s * 0.6 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
    for (int i = 0; i <= s * 0.16; i++)
    {
        display.fillCircle(x + s * 0.5 - i * 0.5, y + s * 0.65 + i, s * 0.02, GxEPD_BLACK);
    }
    display.fillTriangle(x + s * 0.3, y + s * 0.75, x + s * 0.325, y + s * 0.65, x + s * 0.375, y + s * 0.65, GxEPD_RED);
    display.fillTriangle(x + s * 0.3, y + s * 0.75, x + s * 0.4, y + s * 0.7, x + s * 0.33, y + s * 0.7, GxEPD_RED);
    display.fillTriangle(x + s * 0.3, y + s * 0.85, x + s * 0.35, y + s * 0.7, x + s * 0.4, y + s * 0.7, GxEPD_RED);
}

void iconTornado(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t s)
{
    // 1
    fillEllipsis(display, x + s * 0.33, y + s * 0.7, s / 12 * 1.2, s / 18 * 1.2, GxEPD_BLACK);
    fillEllipsis(display, x + s * 0.33, y + s * 0.7, s / 12, s / 18, GxEPD_WHITE);
    // 2
    fillEllipsis(display, x + s * 0.32, y + s * 0.65, s / 9 * 1.2, s / 16 * 1.2, GxEPD_BLACK);
    fillEllipsis(display, x + s * 0.32, y + s * 0.65, s / 9, s / 16, GxEPD_WHITE);
    // 3
    fillEllipsis(display, x + s * 0.35, y + s * 0.55, s / 7 * 1.2, s / 12 * 1.2, GxEPD_BLACK);
    fillEllipsis(display, x + s * 0.35, y + s * 0.55, s / 7, s / 12, GxEPD_WHITE);
    // 4
    fillEllipsis(display, x + s * 0.425, y + s * 0.425, s / 5 * 1.2, s / 8 * 1.2, GxEPD_BLACK);
    fillEllipsis(display, x + s * 0.425, y + s * 0.425, s / 5, s / 8, GxEPD_WHITE);
    // 5
    fillEllipsis(display, x + s * 0.5, y + s * 0.3, s / 4 * 1.2, s / 7 * 1.2, GxEPD_BLACK);
    fillEllipsis(display, x + s * 0.5, y + s * 0.3, s / 4, s / 7, GxEPD_WHITE);
}

// Takes x,y coordinates and radius r and phase. Phase denotes Moons current shape
void iconMoonPhase(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, uint16_t r, float phase)
{
    display.fillCircle(x, y, r, GxEPD_WHITE);
    display.drawCircle(x, y, r, GxEPD_BLACK);
    if (phase == 0)
        display.fillCircle(x, y, r, GxEPD_BLACK); // New Moon
    else if (phase > 0 && phase < 0.5)
    {
        for (int i = 0; i < r + 1; i++)
        {
            float cx = sqrt((r * r) - (i * i));
            float c2 = cx * 2 * (1 - (phase * 2));
            display.drawLine(x - cx, y + i, x - cx + c2, y + i, GxEPD_BLACK);
            display.drawLine(x - cx, y - i, x - cx + c2, y - i, GxEPD_BLACK);
        }
    }
    else if (phase == 0.5)
        ; // display.fillCircle(x, y, r, GxEPD_RED);  //Full Moon
    else
    {
        display.fillCircle(x, y, r, GxEPD_BLACK);
        for (int i = 0; i < r + 1; i++)
        {
            float cx = sqrt((r * r) - (i * i));
            float c2 = cx * 2 * ((1 - phase) * 2);
            display.drawLine(x - cx, y + i, x - cx + c2, y + i, GxEPD_WHITE);
            display.drawLine(x - cx, y - i, x - cx + c2, y - i, GxEPD_WHITE);
        }
        display.drawCircle(x, y, r, GxEPD_BLACK);
    }

    // Add moon surface on top
    display.drawPixel(x - r + 22, y - r + 1, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 3, GxEPD_BLACK);
    display.drawPixel(x - r + 24, y - r + 3, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 4, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 4, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 4, GxEPD_BLACK);
    display.drawPixel(x - r + 24, y - r + 4, GxEPD_BLACK);
    display.drawPixel(x - r + 26, y - r + 4, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 5, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 5, GxEPD_BLACK);
    display.drawPixel(x - r + 26, y - r + 5, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 6, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 6, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 6, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 23, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 25, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 28, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 30, y - r + 7, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 21, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 23, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 26, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 28, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 29, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 31, y - r + 8, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 22, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 23, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 25, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 26, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 28, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 29, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 30, y - r + 9, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 23, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 24, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 26, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 29, y - r + 10, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 21, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 24, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 28, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 30, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 31, y - r + 11, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 21, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 23, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 24, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 25, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 32, y - r + 12, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 22, y - r + 13, GxEPD_BLACK);
    display.drawPixel(x - r + 1, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 25, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 28, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 31, y - r + 14, GxEPD_BLACK);
    display.drawPixel(x - r + 1, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 29, y - r + 15, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 16, GxEPD_BLACK);
    display.drawPixel(x - r + 1, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 4, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 17, GxEPD_BLACK);
    display.drawPixel(x - r + 1, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 18, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 19, GxEPD_BLACK);
    display.drawPixel(x - r + 1, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 20, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 21, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 22, GxEPD_BLACK);
    display.drawPixel(x - r + 2, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 4, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 23, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 4, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 24, GxEPD_BLACK);
    display.drawPixel(x - r + 3, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 5, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 21, y - r + 25, GxEPD_BLACK);
    display.drawPixel(x - r + 4, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 12, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 13, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 26, GxEPD_BLACK);
    display.drawPixel(x - r + 6, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 20, y - r + 27, GxEPD_BLACK);
    display.drawPixel(x - r + 7, y - r + 28, GxEPD_BLACK);
    display.drawPixel(x - r + 8, y - r + 28, GxEPD_BLACK);
    display.drawPixel(x - r + 10, y - r + 28, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 28, GxEPD_BLACK);
    display.drawPixel(x - r + 18, y - r + 28, GxEPD_BLACK);
    display.drawPixel(x - r + 9, y - r + 29, GxEPD_BLACK);
    display.drawPixel(x - r + 11, y - r + 29, GxEPD_BLACK);
    display.drawPixel(x - r + 14, y - r + 29, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 29, GxEPD_BLACK);
    display.drawPixel(x - r + 16, y - r + 29, GxEPD_BLACK);
    display.drawPixel(x - r + 15, y - r + 30, GxEPD_BLACK);
    display.drawPixel(x - r + 19, y - r + 30, GxEPD_BLACK);
    display.drawPixel(x - r + 17, y - r + 31, GxEPD_BLACK);
}

// direction=true (UP), direction=false (DOWN)
void iconSunRise(GxEPD2_3C<GxEPD2_420c_Z21, GxEPD2_420c_Z21::HEIGHT> &display, uint16_t x, uint16_t y, bool direction)
{
    uint16_t r = 7;

    // Horizontal
    display.drawLine(x - r * 2 + 2, y, x + r * 2 - 2, y, GxEPD_BLACK);
    // Vertical
    display.drawLine(x, y - r * 2 + 2, x, y, GxEPD_BLACK);
    // Angle Top right
    display.drawLine(x - r * 2 + 5, y - r * 2 + 5, x, y, GxEPD_BLACK);
    // Angle Top left
    display.drawLine(x, y, x + r * 2 - 5, y - r * 2 + 5, GxEPD_BLACK);
    // Remove lines inside
    display.fillCircle(x, y, r + 1, GxEPD_WHITE);
    // Empty inside
    display.fillCircle(x, y, r - 1, GxEPD_RED);
    display.drawCircle(x, y, r - 1, GxEPD_BLACK);
    // Overwrite the bottom
    display.fillRect(x - r, y + 4, r * 2, r, GxEPD_WHITE);

    // Arrow up
    if (direction == true)
    {
        display.fillTriangle(x - r / 2 - 1, y + r - 2, x, y + r - 7, x + r / 2 + 1, y + r - 2, GxEPD_WHITE);
        display.drawLine(x - r / 2, y + r - 2, x, y + r - 6, GxEPD_BLACK);
        display.drawLine(x, y + r - 6, x + r / 2, y + r - 2, GxEPD_BLACK);
    }
    // Arrow DOWN
    if (direction == false)
    {
        display.drawLine(x - r / 2, y + r - 2, x, y + r + 2, GxEPD_BLACK);
        display.drawLine(x, y + r + 2, x + r / 2, y + r - 2, GxEPD_BLACK);
    }
    // Horizon line
    display.drawLine(x - r, y + r - 2, x - r / 2, y + r - 2, GxEPD_BLACK);
    display.drawLine(x + r / 2, y + r - 2, x + r, y + r - 2, GxEPD_BLACK);
}