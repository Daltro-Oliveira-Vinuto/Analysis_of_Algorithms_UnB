
typedef long long ll;

class Matrix {
public:
	Matrix(ll, ll);
	~Matrix();
	void get_dimensions(ll*, ll*);
	ll get_value(ll, ll);
	void print();
	void update(ll, ll, ll);
	Matrix power(ll);
	Matrix get_identity();
	void copy(const Matrix &);

	Matrix operator + (const Matrix &);
	Matrix operator * (const Matrix &);
	//void operator = (const Matrix &);

private:
	ll rows, cols;
	ll** data;
};

/*
void Matrix::operator = (Matrix const &other) {

	for(ll i = 0; i < rows; i++) {
		for(ll j = 0; j < cols; j++) {
			data[i][j] =  other.data[i][j];
		}
	}
}
*/

Matrix Matrix::power(ll n) {
	if (n == 0) {
		return this->get_identity();
	} else if (n == 1) {
		return *this;
	} else {
		if (n%2 == 0) {
			Matrix result(rows, cols);
			result.copy( this->power(n/2) );

			return result * result;
		} else {
			Matrix result(rows, cols);
			result.copy ( this->power(n/2) ) ;

			return result*result*(*this);
		}
	} 
}


void Matrix::copy(const Matrix &other) {
	for(ll i = 0; i < rows; i++) {
		for(ll j = 0; j< cols; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix Matrix::get_identity() {
	Matrix result(rows, cols);

	for(ll i = 0; i < rows; i++) {
		for(ll j = 0; j < cols; j++) {
			if (i == j) {
				result.update(1, i, j);
			}else {
				result.update(0, i, j);
			}
		}
	}

	return result;
}


ll Matrix::get_value(ll row, ll col) {
	return this->data[row][col];
}

Matrix Matrix::operator * (const Matrix &other) {
	Matrix result(rows, cols);

	for (ll i = 0; i < rows; i++) {
		for(ll j = 0; j < cols; j++) {
			result.update(0, i, j);
			for(ll k = 0; k < cols; k++) {
				result.update(result.get_value(i,j) + data[i][k]*other.data[k][j], i, j);
			}
		}
	}


	return result;
}

Matrix Matrix::operator + (const Matrix &other) {
	Matrix result(rows, cols);

	for(ll i = 0; i < rows; i++) {
		for (ll j = 0; j < cols; j++) {
			result.update(data[i][j] + other.data[i][j],  i, j);
			//printf("i = %lld, j = %lld\n", i, j);
		}
	}

	return result;
}

Matrix::Matrix(ll rows, ll cols) {
	this->rows = rows;
	this->cols = cols;
	
	this->data = (ll**)malloc(sizeof(ll*)*rows);
	for(ll i = 0; i < rows; i++) {
		this->data[i] = (ll*)malloc(sizeof(ll)*cols);
	}

	for(ll i = 0; i < rows; i++) {
		for (ll j = 0; j < cols; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix() {
	for(ll i = 0; i < this->rows; i++) {
		free(this->data[i]);
	}
	free(data);
}

void Matrix::get_dimensions(ll *rows, ll *cols) {
	*rows = this->rows;
	*cols = this->cols;
}

void Matrix::print() {
	for(ll i = 0; i < rows; i++) {
		for(ll j =0; j < cols; j++) {
			printf("%lld ", data[i][j]);
		}
		printf("\n");
	}


}

void Matrix::update(ll elem, ll row, ll col) {
	this->data[row][col] = elem;
}