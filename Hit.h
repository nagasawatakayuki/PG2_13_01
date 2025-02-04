#pragma once
#include <cmath>

/// <summary>
/// 当たり判定関数
/// </summary>
/// <param name="x1">Enemy1のX位置</param>
/// <param name="y1">Enemy1のY位置</param>
/// <param name="r1">Enemy1の半径</param>
/// <param name="x2">Enemy2のX位置</param>
/// <param name="y2">Enemy2のY位置</param>
/// <param name="r2">Enemy2の半径</param>
/// <returns></returns>
inline bool IsCircleHit(int x1, int y1, int r1, int x2, int y2, int r2) {

    int dx = x1 - x2;
    int dy = y1 - y2;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSum = r1 + r2;
    return distanceSquared <= (radiusSum * radiusSum);

}