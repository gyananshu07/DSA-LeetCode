class Solution {
public:
   int countCollisions(string d)
{
	int out{}, l{}, r(size(d)-1);
	for( ; l<size(d) and d[l]=='L'; ++l);
	for( ; r>=0      and d[r]=='R'; --r);
	for( ; l<=r;     out += d[l]=='L' or d[l]=='R', ++l);
	return out;
}
};