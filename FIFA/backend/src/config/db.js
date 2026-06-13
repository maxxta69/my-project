import mongoose from 'mongoose';

mongoose.connect('mongodb://127.0.0.1:27017/testdb')
    .then(() => console.log('Connected to local MongoDB!'))
    .catch((err) => console.error('Connection error:', err));