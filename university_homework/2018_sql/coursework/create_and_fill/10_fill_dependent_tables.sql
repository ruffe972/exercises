USE ershov

DELETE FROM authorship
DBCC CHECKIDENT ('[authorship]', RESEED, 0);
GO
DELETE FROM book_genre
DBCC CHECKIDENT ('[book_genre]', RESEED, 0);
GO
DELETE FROM book_user_record
DBCC CHECKIDENT ('[book_user_record]', RESEED, 0);
GO

INSERT INTO authorship (book_id, author_id) VALUES
(1, 1),
(2, 6),
(3, 6),
(4, 6),
(5, 6),
(6, 6),
(7, 6),
(8, 6),
(9, 2),
(9, 3),
(9, 4),
(9, 5),
(11, 7),
(11, 8),
(12, 9),
(12, 10)

INSERT INTO book_genre (genre_id, book_id, genre_weight) VALUES
(3, 11, 2),
(8, 11, 1),
(2, 12, 1),
(7, 12, 2)

INSERT INTO book_genre (genre_id, book_id) VALUES
(1, 1),
(3, 2),
(3, 3),
(3, 4),
(3, 5),
(3, 6),
(3, 7),
(3, 8),
(1, 9),
(6, 10)

INSERT INTO book_user_record (book_id, site_user_id, rating, book_status, comment) VALUES
(
	1,
	1,
	5,
	'прочитано',
	'Хорошая книга о хорошем языке программирования.'
), (
	2,
	1,
	5,
	'прочитано',
	''
), (
	3,
	1,
	5,
	'прочитано',
	''
), (
	4,
	1,
	5,
	'прочитано',
	''
), (
	5,
	1,
	5,
	'прочитано',
	''
), (
	6,
	1,
	4,
	'прочитано',
	''
), (
	7,
	1,
	5,
	'прочитано',
	''
), (
	8,
	1,
	5,
	'прочитано',
	''
), (
	11,
	1,
	0,
	'к прочтению',
	''
), (
	2,
	2,
	4,
	'прочитано',
	'Неплохо, но ожидал большего.'
), (
	2,
	7,
	3,
	'прочитано',
	'Так себе.'
), (
	2,
	8,
	3,
	'прочитано',
	'Так себе.'
)