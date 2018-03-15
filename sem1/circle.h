class Circle
{
	private:
		float x, y;
		float r;
		
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
	public:
		Circle (float x0, float y0, float r0)
		{
			std:: cout << "Create circle with radius " << r0 << std:: endl;
			x = x0;
			y = y0;
			r = r0;
		}
		~Circle()
		{
			std:: cout << "Deleting circle with radius " << r << std:: endl;
		}
		
		
		
		int is_greater(const Circle& c)
		{
			return r > c.r;
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
