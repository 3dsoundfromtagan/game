class Circle
{
	private:
		float x, y;
		float r;
	public:
		Circle (float x0, float y0, float r0)
		{
			x = x0;
			y = y0;
			r = r0;
		}
		
		float get_x()
		{
			return x;
		}
		
		float get_y()
		{
			return x;
		}
		
		float get_radius()
		{
			return r;
		}
		
		float get_area()
		{
			return 3.1415926 * r * r;
		}
		
		int is_greater(Circle c)
		{
			if (r > c.r)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		int is_intersect(Circle c)
		{
			float dl = (c.x - x) * (c.x - x) + (c.y - y) * (c.y - y);
			if ((dl > (r - c.r) * (r - c.r)) && (dl < (r + c.r) * (r + c.r)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};
