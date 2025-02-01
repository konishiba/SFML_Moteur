#include "Utilities.h"

u_int GetUniqueID()
{
    static u_int _id = 0;
    return ++_id;
}

float DegToRad(const float _degrees)
{
    return _degrees * pi / 180.0f;
}

float RadToDeg(const float _radians)
{
    return 180.0f / pi * _radians;
}

float Lerp(const float _start, const float _end, const float _time)
{
    return _start + _time * (_end - _start);
}

float Lerp_Constant(const float _start, const float _end, const float _time)
{
    return (1 - _time) * _start + _time * _end;
}

float DotProduct(const Vector2f& _direction, const Vector2f& _normal)
{
    return _direction.x * _normal.x + _direction.y * _normal.y;
}

float EaseOutQuart(const float _time)
{
    return 1 - powf(1 - _time, 4.0f);
}

float EaseInQuart(const float _time)
{
    return _time * _time * _time * _time;
}

Vector2f ComputeNormal(const FloatRect& _rect)
{
    const Vector2f& _normal = Vector2f(-_rect.size.y, _rect.size.x);
    const float _norme = Length(_normal);

    return _normal / _norme;
}

float Length(const Vector2f& _vector)
{
    return sqrtf(powf(_vector.x, 2.0f) + powf(_vector.y, 2.0f));
}
