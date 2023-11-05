def draw_pause():
    s = pygame.Surface(SIZE, pygame.SRCALPHA)
    s.fill((255, 255, 255, 220))
    screen.blit(s, (0, 0))
    txt = FONT_M.render('PAUSE', True, COLORS['darkgray'])
    x, y = SIZE[0] / 2, SIZE[1] / 2
    x, y = int(x - FONT_M.size('PAUSE')[0] / 2), int(y - FONT_M.size('PAUSE')[1] / 2)
    screen.blit(txt, (x, y))