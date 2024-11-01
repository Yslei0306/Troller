float data_limit(float target,float limit_up,float limit_down)
{
	if(target > limit_up)
	{
		target = limit_up;
	}
	else if(target < limit_down)
	{
		target = limit_down;
	}
	else if(target < limit_up && target > limit_down)
	{		
		
	}

	return target;
}