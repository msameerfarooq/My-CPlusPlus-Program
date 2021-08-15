bool iscursorkeypressed(int& whickkey)   //whichkey passed as reference.... 
{
	char key;
	key = getasynckeystate(37);
	if (key == 1)
	{
		whickkey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = getasynckeystate(38);
	if (key == 1)
	{

		whickkey = 2;		// 2 if up key is pressed
		return true;
	}

	key = getasynckeystate(39);
	if (key == 1)
	{

		whickkey = 3; // 3 if right key is pressed
		return true;
	}
	key = getasynckeystate(40);
	if (key == 1)
	{

		whickkey = 4;   // 4 if down key is pressed
		return true;
	}
	key = getasynckeystate(13);
	if (key == 1)
	{

		whickkey = 5;   // 4 if down key is pressed
		return true;
	}
	return false;
}
bool iscursorkeypressednew2(int& whickkey)   //whichkey passed as reference.... 
{
	char key;
	key = getasynckeystate(13);
	if (key == 1)
	{
		whickkey = 1;		// 1 if enter key is pressed 
		return true;
	}
	key = getasynckeystate(38);
	if (key == 1)
	{

		whickkey = 2;		// 2 if up key is pressed
		return true;
	}

	key = getasynckeystate(8);
	if (key == 1)
	{

		whickkey = 3; // 3 if backspace is pressed
		return true;
	}
	key = getasynckeystate(40);
	if (key == 1)
	{

		whickkey = 4;   // 4 if down key is pressed
		return true;
	}
	key = getasynckeystate(27);
	if (key == 1)
	{

		whickkey = 5;   // 5 if escape is pressed
		return true;
	}
	return false;
}
void gotoxy(int x, int y)
{
	coord coord;
	coord.x = x;
	coord.y = y;
	setconsolecursorposition(getstdhandle(std_output_handle), coord);

}
void myrect(int x1, int y1, int x2, int y2, int r, int g, int b, int br, int bg, int bb)
{
	hwnd console_handle = getconsolewindow();
	hdc device_context = getdc(console_handle);

	//change the color by changing the values in rgb (from 0-255)
	hpen pen = createpen(ps_solid, 2, rgb(r, g, b));
	selectobject(device_context, pen);
	hbrush brush = ::createsolidbrush(rgb(br, bg, bb)); //fill color is passed as parameter to the function!!!

	selectobject(device_context, brush);

	rectangle(device_context, x1, y1, x2, y2);
	releasedc(console_handle, device_context);
	deleteobject(pen);
	deleteobject(brush);
}
void remove_scrollbar()
{
	handle hstdout = getstdhandle(std_output_handle);
	console_screen_buffer_info csbi;
	getconsolescreenbufferinfo(hstdout, &csbi);

	csbi.dwsize.x = csbi.dwmaximumwindowsize.x;
	csbi.dwsize.y = csbi.dwmaximumwindowsize.y;
	setconsolescreenbuffersize(hstdout, csbi.dwsize);

	hwnd x_x = getconsolewindow();
	showscrollbar(x_x, sb_both, false);
}
void setfontsize(int fontsize)
{
	console_font_infoex info = { 0 };
	info.cbsize = sizeof(info);
	info.dwfontsize.y = fontsize; // leave x as zero
	info.fontweight = fw_normal;
	setcurrentconsolefontex(getstdhandle(std_output_handle), null, &info);
}