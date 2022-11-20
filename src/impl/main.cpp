#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class olcPGEtest : public olc::PixelGameEngine
{
public:
	olcPGEtest()
	{
		sAppName = "olcPGE test";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++) {
                olc::Pixel pix;
                if (x > 30 && x < 226 && y > 30 && y < 210)
                    pix = olc::Pixel(255, 50, 0);
                else
                    pix = olc::Pixel(
                            rand() % 255,
                            rand() % 255,
                            rand() % 255);
				Draw(x, y, pix);	
            }
		return true;
	}
};


int main()
{
	olcPGEtest instance;
	if (instance.Construct(256, 240, 4, 4))
	    instance.Start();

	return 0;
}
