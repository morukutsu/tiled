#ifndef PERSPECTIVERENDERER_H
#define PERSPECTIVERENDERER_H

#include "maprenderer.h"

namespace Tiled {

/**
 * OpenGL renderer of orthogonal maps with perspective correction
 */
class TILEDSHARED_EXPORT PerspectiveRenderer : public MapRenderer
{
public:
    PerspectiveRenderer(const Map *map) : MapRenderer(map) {}

    QSize mapSize() const;

    QRect boundingRect(const QRect &rect) const;

    QRectF boundingRect(const MapObject *object) const;
    QPainterPath shape(const MapObject *object) const;

    void drawGrid(QPainter *painter, const QRectF &rect,
                  QColor gridColor) const;

    void drawTileLayer(QPainter *painter, const TileLayer *layer,
                       const QRectF &exposed = QRectF()) const;

    void drawTileSelection(QPainter *painter,
                           const QRegion &region,
                           const QColor &color,
                           const QRectF &exposed) const;

    void drawMapObject(QPainter *painter,
                       const MapObject *object,
                       const QColor &color) const;

    QPointF pixelToTileCoords(qreal x, qreal y) const;

    using MapRenderer::tileToPixelCoords;
    QPointF tileToPixelCoords(qreal x, qreal y) const;
};

} // namespace Tiled

#endif // PERSPECTIVERENDERER_H
